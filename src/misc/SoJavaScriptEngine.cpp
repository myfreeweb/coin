/**************************************************************************\
 *  
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *  
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *    
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#ifdef COIN_HAVE_JAVASCRIPT
  
#include <Inventor/misc/SoJavaScriptEngine.h>
#include <Inventor/errors/SoDebugError.h>
#include <Inventor/C/tidbitsp.h>

// FIXME: Do this in a nicer way. 20050714 erikgors.
#include "../vrml97/JS_VRMLClasses.cpp"

#undef PRIVATE
#undef PUBLIC
#define PRIVATE(p) (p->pimpl)
#define PUBLIC(p) (p->master)

class SoJavaScriptEngineP {
public:
  SoJavaScriptEngineP(SoJavaScriptEngine * node) : master(node) {};
  SbBool executeJSScript(JSScript * script) const;

  static size_t CONTEXT_STACK_CHUNK_SIZE; /* stack chunk size */
  static JSRuntime * runtime;
  JSContext * context;
  JSObject * global;

  struct JavascriptHandler {
    SoType type;
    SoJSWrapperInitFunc * init;
    SoJSfield2jsvalFunc * field2jsval;
    SoJSjsval2field2Func * jsval2field;
  };

  SbList<JavascriptHandler> handlerList;
  SoJavaScriptEngine * master;
};

JSRuntime * SoJavaScriptEngineP::runtime = NULL;
size_t SoJavaScriptEngineP::CONTEXT_STACK_CHUNK_SIZE = 8192; /* stack chunk size */

/*!
  Execute a compiled script.
 */
SbBool
SoJavaScriptEngineP::executeJSScript(JSScript * script) const
{
  jsval rval;
  JSBool ok = spidermonkey()->JS_ExecuteScript(this->context, this->global, script, &rval);
  if (ok) {
    if (SoJavaScriptEngine::debug()) {
      JSString * str = spidermonkey()->JS_ValueToString(this->context, rval);
      SoDebugError::postInfo("SoJavaScriptEngineP::executeJSScript",
                             "script result: '%s'",
                             spidermonkey()->JS_GetStringBytes(str));
    }
    return TRUE;
  }
  else {
    // FIXME: improve on this. 20050526 mortene.
    SoDebugError::postWarning("SoJavaScriptEngine::executeJSScript",
                              "Script evaluation failed!");
  }
  return FALSE;
}

// FIXME: imported from SquirrelMonkey/src/jsutils.cpp
// 20050719 erikgors.
/*!
  Prints a stacktrace for the pending exception.
  Does nothing if there aren't any pending exceptions.
*/
static void printJSException(JSContext *cx)
{
  jsval val, stack;
  JSObject * obj;
  char * cstr;
  int len;
  JSString *s;

  if (!spidermonkey()->JS_GetPendingException(cx, &val)) return;
  if (!JSVAL_IS_OBJECT(val)) return;
  obj = JSVAL_TO_OBJECT(val);
  if (!spidermonkey()->JS_GetProperty(cx, obj, "stack", &stack)) return;

  /* print exception.stack */
  if (!(s=spidermonkey()->JS_ValueToString(cx, stack))) {
    SoDebugError::postWarning("printJSException", "could not convert exception to string");
    return;
  }
  /* root the string */
  if (!spidermonkey()->JS_AddRoot(cx, &s)) {
    SoDebugError::postWarning("printJSException", "could not root string");
    return;
  }

  /* Todo: we loose unicode information here */
  cstr = spidermonkey()->JS_GetStringBytes(s);
  if (!cstr) {
    SoDebugError::postWarning("printJSException", "could not get string bytes");
    assert(spidermonkey()->JS_RemoveRoot(cx, &s));
    return;
  }
  len = spidermonkey()->JS_GetStringLength(s);
  SoDebugError::postWarning("printJSException", "Stack:");
  /*
     Todo: somehow do nice indent
     Note: string might contain \0 => we don't use fputs
  */
  // FIXME: this looks ugly. 20050719 erikgors.
  fwrite(cstr, 1, spidermonkey()->JS_GetStringLength(s), stderr);
  fprintf(stderr, "\n");
  assert(spidermonkey()->JS_RemoveRoot(cx, &s));
}

/*!
  Default Error Handler for Coin
 */
static void SpiderMonkey_ErrorHandler(JSContext * cx, const char * message, 
                                      JSErrorReport * report)
{                               
  SoDebugError::postWarning("SpiderMonkey_ErrorHandler",
                            "%s:%d: %s:\n  %s\n",
                            report->filename, report->lineno, message, 
                            report->linebuf);
  printJSException(cx);
}   

/*!
  Easy to use print function for spidermonkey.
  print("hello", "world", 123, obj) will return "hello world 123 [some obj]"
 */
static JSBool JavascriptPrint(JSContext * cx, JSObject * obj, 
                              uintN argc, jsval * argv, jsval * rval)
{
  SbString out;

  if (argc > 0) {
    // " ".join(argv)
    uintN i;
    for (i=0; i<argc-1; ++i) {
      out += spidermonkey()->JS_GetStringBytes(spidermonkey()->JS_ValueToString(cx, argv[i]));
      out += " ";
    }
    out += spidermonkey()->JS_GetStringBytes(spidermonkey()->JS_ValueToString(cx, argv[i]));
  }
  
  SoDebugError::postInfo("JavascriptPrint", out.getString());
  return JS_TRUE;
}

/*!
  Constructor. Will create a new context and global spidermonkey object
  for this object.
 */
SoJavaScriptEngine::SoJavaScriptEngine()
{
  PRIVATE(this) = new SoJavaScriptEngineP(this); 

  JSContext * cx = PRIVATE(this)->context = 
    spidermonkey()->JS_NewContext(SoJavaScriptEngine::getRuntime(), 
                                  SoJavaScriptEngineP::CONTEXT_STACK_CHUNK_SIZE);
  if (!cx) {
    SoDebugError::postWarning("SoJavaScriptEngine::SoJavaScriptEngine",
                              "SpiderMonkey Javascript engine available, "
                              "but failed to set up a JSContext!");
    SoJavaScriptEngine::shutdown();
    return;
  }

  (void)spidermonkey()->JS_SetErrorReporter(cx, SpiderMonkey_ErrorHandler);

  static JSClass jclass = {
    "SoJavaScriptEngine_global", 0,
    spidermonkey()->JS_PropertyStub,
    spidermonkey()->JS_PropertyStub,
    spidermonkey()->JS_PropertyStub,
    spidermonkey()->JS_PropertyStub,
    spidermonkey()->JS_EnumerateStub,
    spidermonkey()->JS_ResolveStub,
    spidermonkey()->JS_ConvertStub, 
    spidermonkey()->JS_FinalizeStub,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0
  };

  // FIXME: add global as an argument, so more than one context can share
  // the same global object? 20050719 erikgors.
  JSObject * global = PRIVATE(this)->global = 
    spidermonkey()->JS_NewObject(cx, &jclass, NULL, NULL);
  if (!global) {
    SoDebugError::postWarning("SoJavaScriptEngine::SoJavaScriptEngine",
                              "SpiderMonkey Javascript engine available, "
                              "but failed to set up a global JSObject!");
    SoJavaScriptEngine::shutdown();
    return;
  }

  // JS_InitStandardClasses also adds gc protection and sets cx's global
  // 20050719 erikgors.
  JSBool ok = spidermonkey()->JS_InitStandardClasses(cx, global);
  if (!ok) {
    SoDebugError::postWarning("SoJavaScriptEngine::SoJavaScriptEngine",
                              "SpiderMonkey Javascript engine available, "
                              "but failed to init standard classes for "
                              "global JSObject!");
    SoJavaScriptEngine::shutdown();
    return;
  }

  // FIXME: maybe this should be optional? 20050719 erikgors.
  spidermonkey()->JS_DefineFunction(cx, global, "print", JavascriptPrint, 0, 0);

  // Make the engine accessable from within the context
  spidermonkey()->JS_SetContextPrivate(cx, this);

  JS_addVRMLclasses(this);
}

/*!
  Destructor. Will destroy the spidermonkey context

  FIXME: Should we destroy a context that was set externally 
  using setContext()? (assuming that setContext will be made public)
  kintel 20050920
 */
SoJavaScriptEngine::~SoJavaScriptEngine()
{
  spidermonkey()->JS_DestroyContext(PRIVATE(this)->context);
  delete PRIVATE(this);
}

/*!
  Returns spidermonkey runtime instance for this class.
 */
JSRuntime *
SoJavaScriptEngine::getRuntime(void)
{
  return SoJavaScriptEngineP::runtime;
}
    
/*!
  Set the spidermonkey runtime for this class
 */
void
SoJavaScriptEngine::setRuntime(JSRuntime * runtime)
{
  SoJavaScriptEngineP::runtime = runtime;
}

/*!
  Returns spidermonkey context for this object.
 */
JSContext *
SoJavaScriptEngine::getContext(void)
{
  return PRIVATE(this)->context;
}
    
/*!
  Set the spidermonkey context for this object.
 */
void
SoJavaScriptEngine::setContext(JSContext * context)
{
  // FIXME: reassociate this with the given context?  kintel 20050920
  PRIVATE(this)->context = context;
}

/*!
  Returns spidermonkey global object for this object.
 */
JSObject *
SoJavaScriptEngine::getGlobal(void)
{
  // FIXME: Get using JS_GetGlobalObject()? kintel 20050920
  return PRIVATE(this)->global;
}
    
/*!
  Set the spidermonkey global object for this object.
 */
void
SoJavaScriptEngine::setGlobal(JSObject * global)
{
  PRIVATE(this)->global = global;
  // FIXME: Also set using JS_SetGlobalObject()? kintel 20050920
}

/*!
 Init the spidermonkey runtime.
 */
void
SoJavaScriptEngine::init(uint32_t maxBytes)
{
  assert(SoJavaScriptEngine::getRuntime() == NULL);
  JSRuntime * rt = spidermonkey()->JS_NewRuntime(maxBytes);

  if (rt == NULL) {
    SoDebugError::postWarning("SoJavaScriptEngine::init",
                              "SpiderMonkey Javascript engine available, "
                              "but failed to instantiate a JSRuntime!");
    return;
  }
  SoJavaScriptEngine::setRuntime(rt);
}

/*!
 Shutdown the spidermonkey runtime.
 */
void
SoJavaScriptEngine::shutdown(void)
{
  JSRuntime * rt = SoJavaScriptEngine::getRuntime();
  if (rt != NULL) {
    spidermonkey()->JS_DestroyRuntime(rt);
  }

  spidermonkey()->JS_ShutDown();
  SoJavaScriptEngine::setRuntime(NULL);
}

SbBool
SoJavaScriptEngine::debug(void)
{
  static int d = -1;
  if (d == -1) {
    const char * env = coin_getenv("COIN_DEBUG_VRMLSCRIPT");
    d = (env && (atoi(env) > 0)) ? 1 : 0;

  }
  return d ? TRUE : FALSE;
}

/*!
  Compile and execute a string containing a script.
 */
SbBool
SoJavaScriptEngine::executeScript(const SbName & name, const SbString & script) const
{
  if (SoJavaScriptEngine::debug()) {
    SoDebugError::postInfo("SoJavaScriptEngine::executeScript", "script=='%s'",
                           script.getString());
  }

  // FIXME: should set a correct linenum offset, for better error messages.
  // 20050728 erikgors.
  JSScript * jsscript =
    spidermonkey()->JS_CompileScript(PRIVATE(this)->context,
                                     PRIVATE(this)->global,
                                     script.getString(), script.getLength(),
                                     name.getString(), 1);

  return PRIVATE(this)->executeJSScript(jsscript);
}

/*!
  Compile and execute a file.
 */
SbBool
SoJavaScriptEngine::executeFile(const SbName & filename) const
{
  if (SoJavaScriptEngine::debug()) {
    SoDebugError::postInfo("SoJavaScriptEngine::executeFile", "filename=='%s'", filename.getString());
  }

  JSScript * script = spidermonkey()->JS_CompileFile(PRIVATE(this)->context, PRIVATE(this)->global, filename);

  return PRIVATE(this)->executeJSScript(script);
}

/*!
  Execute a function in the global spidermonkey object.
 */
SbBool
SoJavaScriptEngine::executeFunction(const SbName & name, 
                                    int argc, const SoField * argv, 
                                    SoField * rval) const
{
  jsval * jsargv = new jsval[argc];

  for (int i=0; i<argc; ++i) {
    field2jsval(&argv[i], &jsargv[i]);
  }

  jsval rjsval;
  JSBool ok =
    spidermonkey()->JS_CallFunctionName(PRIVATE(this)->context, PRIVATE(this)->global,
                                        name.getString(), argc, jsargv, &rjsval);
  delete [] jsargv;

  if (ok) {
    if (SoJavaScriptEngine::debug()) {
      JSString * str = spidermonkey()->JS_ValueToString(PRIVATE(this)->context, rjsval);
      SoDebugError::postInfo("SoJavaScriptEngine::executeFunction",
                             "function: \"%s\" "
                             "result: '%s'",
                             name.getString(), spidermonkey()->JS_GetStringBytes(str));
    }

    SbBool ok2 = TRUE;
    if (rval != NULL) {
      ok2 = jsval2field(rjsval, rval);
    }
    return ok2;
  }
  else {
    SoDebugError::postWarning("SoJavaScriptEngine::executeFunctions",
                              "JS_CallFunctionName(..., \"%s\", ...) "
                              "failed!", name.getString());
    return FALSE;
  }
}

/*!
  Convert a SoField object to a native spidermonkey value.
 */
SbBool
SoJavaScriptEngine::field2jsval(const SoField * f, jsval * v) const
{
  int n = PRIVATE(this)->handlerList.getLength();

  // go backwards. new handlers has precedence. 20050719 erikgors.
  while (n --> 0) {
    const SoJavaScriptEngineP::JavascriptHandler & handler = PRIVATE(this)->handlerList[n];

    if (handler.field2jsval != NULL && f->isOfType(handler.type)) {
      handler.field2jsval(PRIVATE(this)->context, f, v);
      return TRUE;
    }
  }
  SoDebugError::postInfo("SoJavaScriptEngine::field2jsval", "no handler found for %s", f->getTypeId().getName().getString());
  *v = JSVAL_VOID;
  return FALSE;
}

/*!
  Returns the SoJavaScriptEngine associated with the given context.
  If the context isn't associated with an SoJavaScriptEngine it will 
  return NULL.

  NB! Setting the context private data (using JS_SetContextPrivate()) will
  overwrite this information and cause this method to return a garbage
  pointer.
*/
SoJavaScriptEngine *
SoJavaScriptEngine::getEngine(JSContext * cx)
{
  return (SoJavaScriptEngine *)spidermonkey()->JS_GetContextPrivate(cx);
}

/*!
  Convert a native spidermonkey value to a SoField object.
 */
SbBool 
SoJavaScriptEngine::jsval2field(const jsval v, SoField * f) const
{
  int n = PRIVATE(this)->handlerList.getLength();

  // go backwards. new handlers has precedence. 20050719 erikgors.
  while (n --> 0) {
    const SoJavaScriptEngineP::JavascriptHandler & handler = PRIVATE(this)->handlerList[n];

    if (handler.jsval2field != NULL && f->isOfType(handler.type)) {
      if (handler.jsval2field(PRIVATE(this)->context, v, f)) {
        return TRUE;
      }
      else {
        JSString * jsstr = spidermonkey()->JS_ValueToString(PRIVATE(this)->context, v); 
        const char * str = spidermonkey()->JS_GetStringBytes(jsstr);
        SoDebugError::postWarning("SoJavaScriptEngine::jsval2field",
                                  "convertion of '%s' to SoField type '%s' failed",
                                  str, handler.type.getName().getString());
        return FALSE;
      }
    }
  }
  SoDebugError::postInfo("SoJavaScriptEngine::jsval2field", "no handler found for %s", f->getTypeId().getName().getString());
  return FALSE;
}

/*!
  Adds a JavaScript handler for an SoField subtype.

  \a init is the class init function and will be called immediately 
  if specified.
  \a field2jsval and \a jsval2field will convert an SoField to a jsval 
  or vice versa. Setting these to NULL is allowed but will result in the 
  fields not being accessible from JavaScript.

  New handlers will get precedence over old handlers.
*/
void
SoJavaScriptEngine::addHandler(const SoType & type, 
                               SoJSWrapperInitFunc * init, 
                               SoJSfield2jsvalFunc * field2jsval, 
                               SoJSjsval2field2Func * jsval2field)
{
  SoJavaScriptEngineP::JavascriptHandler handler;
  handler.type = type;
  handler.init = init;
  handler.field2jsval = field2jsval;
  handler.jsval2field = jsval2field;

  PRIVATE(this)->handlerList.append(handler);

  if (handler.init != NULL) {
    handler.init(PRIVATE(this)->context, PRIVATE(this)->global);
  }
}

/*!
  Set a script field.
 */
SbBool
SoJavaScriptEngine::setScriptField(const SbName & name, const SoField * f) const
{
  jsval initval;
  field2jsval(f, &initval);
  const JSBool ok =
    spidermonkey()->JS_SetProperty(PRIVATE(this)->context,
                                   PRIVATE(this)->global,
                                   name.getString(), &initval);
  if (!ok) {
    SoDebugError::post("SoJavaScriptEngine::setScriptField",
                       "Could not set field '%s' for "
                       "Javascript engine.", name.getString());
  }
  return ok;
}

/*!
  Unset a script field.
 */
SbBool
SoJavaScriptEngine::unsetScriptField(const SbName & name) const
{
  const JSBool ok =
    spidermonkey()->JS_DeleteProperty(PRIVATE(this)->context,
                                      PRIVATE(this)->global,
                                      name.getString());
  if (!ok) {
    SoDebugError::post("SoJavaScriptEngine::unsetScriptField",
                       "Could not unset field '%s' for "
                       "Javascript engine.", name.getString());
  }
  return ok;
}

/*!
  Get a script field.
 */
SbBool
SoJavaScriptEngine::getScriptField(const SbName & name, SoField * f) const
{
    jsval val;
    const JSBool ok = spidermonkey()->JS_GetProperty(PRIVATE(this)->context, PRIVATE(this)->global,
                                                     name.getString(), &val);
    if (!ok) {
      SoDebugError::post("SoJavaScriptEngine::getScriptField",
                         "Could not find field '%s' as SpiderMonkey "
                         "object property!", name.getString());
      return FALSE;
    }
    if (SoJavaScriptEngine::debug()) {
      JSString * str = spidermonkey()->JS_ValueToString(PRIVATE(this)->context, val);
      SoDebugError::postInfo("SoJavaScriptEngine::getScriptField", "trying to convert"
                             " \"%s\" to type %s", spidermonkey()->JS_GetStringBytes(str),
                             f->getTypeId().getName().getString());
    }


    return jsval2field(val, f);
}

SbBool
SoJavaScriptEngine::hasScriptField(const SbName & name) const
{
  jsval val;
  assert(spidermonkey()->JS_GetProperty(PRIVATE(this)->context, PRIVATE(this)->global,
                                        name.getString(), &val));

  return JSVAL_IS_VOID(val) ? FALSE : TRUE;
}

#undef PRIVATE
#undef PUBLIC

#endif // !COIN_HAVE_JAVASCRIPT 