/**************************************************************************\
 * 
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 73540378 Fax: +47 73943861
 *
\**************************************************************************/

#ifndef __CONFDEP_H__
#define __CONFDEP_H__

// This file contains the configuration dependency settings. The rules
// specified here are absolutely necessary to get the "make config"
// scheme to work.
//
// Lines beginning with ``//#'' defines rules for the configuration
// settings. These blocks of rules can be exploded (and updated) from
// Emacs by the function `coin-explode-rule-block' in
// <Coin/scripts/coin.el>. To use, first do a `load-file' invocation
// on coin.el. From now on, you should be able to place the cursor
// anywhere within a rule block and execute `coin-explode-rule-block'
// to automatically expand the rules into C code.
//
// Its convenient to use shortkeys for this operation, and to install
// the elisp code such that it gets automaticlly loaded upon the first
// invocation. Here's what my setup in the $HOME/.emacs file looks
// like:
//
//  (load-file "/home/mortene/code/Coin/scripts/coin.el")
//  (global-unset-key "\C-o")
//  (global-set-key "\C-o\C-e" 'coin-explode-conf-rule)
//  (global-set-key "\C-o\C-i" 'coin-implode-conf-block)
//
// I can then hit Control-o-e or Control-o-i to quickly expand or
// implode the rule blocks and C code define blocks, respectively.
//
// NB: there is one known limitation in the elisp code. Make sure
// there is at least one blank line between two rule blocks, or the
// explode code will not work properly.
//
// 19990523 mortene.


// FIXME: should set up the dependency rules locally within each
// class' header (.h) or implementation (.cpp) file, and autogenerate
// this file from that. A scheme like this would make it easier to
// keep the rules in sync with the actual code.
//
// 19990630 mortene.


// ** SOF ******************************************************************


// FIXME: exclusion mechanisms are temporarily disabled while the
// conversion to autoconf-based build is in progress. 19990912 mortene.
#if 1
#define COIN_EXCLUDE_NOTHING 1
#endif

// Don't use the configuration dependency setup if we're compiling our
// minimalist version of the library.
#if defined(__SOLIB_MAKEASBASE__)
#define COIN_EXCLUDE_NOTHING 1
#endif // __SOLIB_MAKEASBASE__



// Use the configuration rules only if the global "compile everything"
// flag is not set.
#if !defined(COIN_EXCLUDE_NOTHING)

// This is the "raw" auto-generated configuration settings file.
#define _INCLUDED_FROM_CONFDEP_H_
#include <Inventor/soconfig.h>
#undef _INCLUDED_FROM_CONFDEP_H_

///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Engines' dependency rules                                 //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

// Disable subclass(es).

//# !SoEngine: !SoBoolOperation, !SoCalculator, !SoComposeVec2f,
//#   !SoComposeVec3f, !SoComposeVec4f, !SoDecomposeVec2f, !SoDecomposeVec3f,
//#   !SoDecomposeVec4f, !SoComposeRotation, !SoComposeRotationFromTo,
//#   !SoDecomposeRotation, !SoComposeMatrix, !SoDecomposeMatrix,
//#   !SoComputeBoundingBox, !SoConcatenate, !SoCounter, !SoElapsedTime,
//#   !SoFieldConverter, !SoGate, !SoInterpolate, !SoOnOff, !SoOneShot,
//#   !SoSelectOne !SoTimeCounter, !SoTransformVec3f, !SoTriggerAny
#if defined(COIN_EXCLUDE_SOENGINE) // (AUTOGEN)
#define COIN_EXCLUDE_SOBOOLOPERATION 1
#define COIN_EXCLUDE_SOCALCULATOR 1
#define COIN_EXCLUDE_SOCOMPOSEVEC2F 1
#define COIN_EXCLUDE_SOCOMPOSEVEC3F 1
#define COIN_EXCLUDE_SOCOMPOSEVEC4F 1
#define COIN_EXCLUDE_SODECOMPOSEVEC2F 1
#define COIN_EXCLUDE_SODECOMPOSEVEC3F 1
#define COIN_EXCLUDE_SODECOMPOSEVEC4F 1
#define COIN_EXCLUDE_SOCOMPOSEROTATION 1
#define COIN_EXCLUDE_SOCOMPOSEROTATIONFROMTO 1
#define COIN_EXCLUDE_SODECOMPOSEROTATION 1
#define COIN_EXCLUDE_SOCOMPOSEMATRIX 1
#define COIN_EXCLUDE_SODECOMPOSEMATRIX 1
#define COIN_EXCLUDE_SOCOMPUTEBOUNDINGBOX 1
#define COIN_EXCLUDE_SOCONCATENATE 1
#define COIN_EXCLUDE_SOCOUNTER 1
#define COIN_EXCLUDE_SOELAPSEDTIME 1
#define COIN_EXCLUDE_SOFIELDCONVERTER 1
#define COIN_EXCLUDE_SOGATE 1
#define COIN_EXCLUDE_SOINTERPOLATE 1
#define COIN_EXCLUDE_SOONOFF 1
#define COIN_EXCLUDE_SOONESHOT 1
#define COIN_EXCLUDE_SOSELECTONE 1
#define COIN_EXCLUDE_SOTIMECOUNTER 1
#define COIN_EXCLUDE_SOTRANSFORMVEC3F 1
#define COIN_EXCLUDE_SOTRIGGERANY 1
#endif // COIN_EXCLUDE_SOENGINE  (AUTOGEN)

//# !SoFieldConverter: !SoConvertAll
#if defined(COIN_EXCLUDE_SOFIELDCONVERTER) // (AUTOGEN)
#define COIN_EXCLUDE_SOCONVERTALL 1
#endif // COIN_EXCLUDE_SOFIELDCONVERTER  (AUTOGEN)

//# !SoInterpolate: !SoInterpolateFloat, !SoInterpolateRotation,
//#   !SoInterpolateVec2f, !SoInterpolateVec3f, !SoInterpolateVec4f
#if defined(COIN_EXCLUDE_SOINTERPOLATE) // (AUTOGEN)
#define COIN_EXCLUDE_SOINTERPOLATEFLOAT 1
#define COIN_EXCLUDE_SOINTERPOLATEROTATION 1
#define COIN_EXCLUDE_SOINTERPOLATEVEC2F 1
#define COIN_EXCLUDE_SOINTERPOLATEVEC3F 1
#define COIN_EXCLUDE_SOINTERPOLATEVEC4F 1
#endif // COIN_EXCLUDE_SOINTERPOLATE  (AUTOGEN)



///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Nodes' dependency rules                                   //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

//# !SoNode: !SoCamera, !SoShape, !SoAnnoText3Property, !SoGroup,
//#   !SoTransformation, !SoBaseColor, !SoCallback, !SoClipPlane,
//#   !SoColorIndex, !SoComplexity, !SoCoordinate3, !SoCoordinate4, !SoLight,
//#   !SoDrawStyle, !SoEnvironment, !SoEventcallback, !SoFile, !SoFont,
//#   !SoInfo, !SoLabel, !SoLightModel, !SoProfile, !SoMaterial,
//#   !SoMaterialBinding, !SoNormal, !SoNormalBinding, !SoPackedColor,
//#   !SoPickStyle, !SoPolygonOffset, !SoProfileCoordinate2,
//#   !SoProfileCoordinate3, !SoShapeHints, !SoTexture2, !SoTexture2Transform,
//#   !SoTextureCoordinate2, !SoTextureCoordinateBinding,
//#   !SoTextureCoordinateFunction, !SoVertexProperty, !SoWWWInline
#if defined(COIN_EXCLUDE_SONODE) // (AUTOGEN)
#define COIN_EXCLUDE_SOCAMERA 1
#define COIN_EXCLUDE_SOSHAPE 1
#define COIN_EXCLUDE_SOANNOTEXT3PROPERTY 1
#define COIN_EXCLUDE_SOGROUP 1
#define COIN_EXCLUDE_SOTRANSFORMATION 1
#define COIN_EXCLUDE_SOBASECOLOR 1
#define COIN_EXCLUDE_SOCALLBACK 1
#define COIN_EXCLUDE_SOCLIPPLANE 1
#define COIN_EXCLUDE_SOCOLORINDEX 1
#define COIN_EXCLUDE_SOCOMPLEXITY 1
#define COIN_EXCLUDE_SOCOORDINATE3 1
#define COIN_EXCLUDE_SOCOORDINATE4 1
#define COIN_EXCLUDE_SOLIGHT 1
#define COIN_EXCLUDE_SODRAWSTYLE 1
#define COIN_EXCLUDE_SOENVIRONMENT 1
#define COIN_EXCLUDE_SOEVENTCALLBACK 1
#define COIN_EXCLUDE_SOFILE 1
#define COIN_EXCLUDE_SOFONT 1
#define COIN_EXCLUDE_SOINFO 1
#define COIN_EXCLUDE_SOLABEL 1
#define COIN_EXCLUDE_SOLIGHTMODEL 1
#define COIN_EXCLUDE_SOPROFILE 1
#define COIN_EXCLUDE_SOMATERIAL 1
#define COIN_EXCLUDE_SOMATERIALBINDING 1
#define COIN_EXCLUDE_SONORMAL 1
#define COIN_EXCLUDE_SONORMALBINDING 1
#define COIN_EXCLUDE_SOPACKEDCOLOR 1
#define COIN_EXCLUDE_SOPICKSTYLE 1
#define COIN_EXCLUDE_SOPOLYGONOFFSET 1
#define COIN_EXCLUDE_SOPROFILECOORDINATE2 1
#define COIN_EXCLUDE_SOPROFILECOORDINATE3 1
#define COIN_EXCLUDE_SOSHAPEHINTS 1
#define COIN_EXCLUDE_SOTEXTURE2 1
#define COIN_EXCLUDE_SOTEXTURE2TRANSFORM 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATE2 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION 1
#define COIN_EXCLUDE_SOVERTEXPROPERTY 1
#define COIN_EXCLUDE_SOWWWINLINE 1
#endif // COIN_EXCLUDE_SONODE  (AUTOGEN)

//# !SoShape: !SoAnnoText3, !SoAsciiText, !SoCone, !SoCube, !SoCylinder,
//#   !SoVertexShape, !SoImage, !SoIndexedNurbsCurve, !SoIndexedNurbsSurface,
//#   !SoNurbsCurve, !SoNurbsSurface, !SoSphere, !SoText2, !SoText3
#if defined(COIN_EXCLUDE_SOSHAPE) // (AUTOGEN)
#define COIN_EXCLUDE_SOANNOTEXT3 1
#define COIN_EXCLUDE_SOASCIITEXT 1
#define COIN_EXCLUDE_SOCONE 1
#define COIN_EXCLUDE_SOCUBE 1
#define COIN_EXCLUDE_SOCYLINDER 1
#define COIN_EXCLUDE_SOVERTEXSHAPE 1
#define COIN_EXCLUDE_SOIMAGE 1
#define COIN_EXCLUDE_SOINDEXEDNURBSCURVE 1
#define COIN_EXCLUDE_SOINDEXEDNURBSSURFACE 1
#define COIN_EXCLUDE_SONURBSCURVE 1
#define COIN_EXCLUDE_SONURBSSURFACE 1
#define COIN_EXCLUDE_SOSPHERE 1
#define COIN_EXCLUDE_SOTEXT2 1
#define COIN_EXCLUDE_SOTEXT3 1
#endif // COIN_EXCLUDE_SOSHAPE  (AUTOGEN)

//# !SoVertexShape: !SoNonIndexedShape, !SoIndexedShape
#if defined(COIN_EXCLUDE_SOVERTEXSHAPE) // (AUTOGEN)
#define COIN_EXCLUDE_SONONINDEXEDSHAPE 1
#define COIN_EXCLUDE_SOINDEXEDSHAPE 1
#endif // COIN_EXCLUDE_SOVERTEXSHAPE  (AUTOGEN)

//# !SoGroup: !SoSeparator, !SoArray, !SoSwitch, !SoLOD, !SoLevelOfDetail,
//#   !SoMultipleCopy, !SoPathSwitch, !SoTransformSeparator
#if defined(COIN_EXCLUDE_SOGROUP) // (AUTOGEN)
#define COIN_EXCLUDE_SOSEPARATOR 1
#define COIN_EXCLUDE_SOARRAY 1
#define COIN_EXCLUDE_SOSWITCH 1
#define COIN_EXCLUDE_SOLOD 1
#define COIN_EXCLUDE_SOLEVELOFDETAIL 1
#define COIN_EXCLUDE_SOMULTIPLECOPY 1
#define COIN_EXCLUDE_SOPATHSWITCH 1
#define COIN_EXCLUDE_SOTRANSFORMSEPARATOR 1
#endif // COIN_EXCLUDE_SOGROUP  (AUTOGEN)

//# !SoSwitch: !SoBlinker
#if defined(COIN_EXCLUDE_SOSWITCH) // (AUTOGEN)
#define COIN_EXCLUDE_SOBLINKER 1
#endif // COIN_EXCLUDE_SOSWITCH  (AUTOGEN)

//# !SoLOD: !SoLevelOfSimplification
#if defined(COIN_EXCLUDE_SOLOD) // (AUTOGEN)
#define COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION 1
#endif // COIN_EXCLUDE_SOLOD  (AUTOGEN)

//# !SoNonIndexedShape: !SoFaceSet, !SoLineSet, !SoPointSet, !SoQuadMesh,
//#   !SoTriangleStripSet
#if defined(COIN_EXCLUDE_SONONINDEXEDSHAPE) // (AUTOGEN)
#define COIN_EXCLUDE_SOFACESET 1
#define COIN_EXCLUDE_SOLINESET 1
#define COIN_EXCLUDE_SOPOINTSET 1
#define COIN_EXCLUDE_SOQUADMESH 1
#define COIN_EXCLUDE_SOTRIANGLESTRIPSET 1
#endif // COIN_EXCLUDE_SONONINDEXEDSHAPE  (AUTOGEN)

//# !SoSeparator: !SoAnnotation, !SoSelection, !SoLocateHighlight
#if defined(COIN_EXCLUDE_SOSEPARATOR) // (AUTOGEN)
#define COIN_EXCLUDE_SOANNOTATION 1
#define COIN_EXCLUDE_SOSELECTION 1
#define COIN_EXCLUDE_SOLOCATEHIGHLIGHT 1
#endif // COIN_EXCLUDE_SOSEPARATOR  (AUTOGEN)

//# !SoTransformation: !SoAntiSquish, !SoMatrixTransform, !SoRotation,
//#   !SoResetTransform, !SoRotationXYZ, !SoScale, !SoSurroundScale,
//#   !SoTranslation, !SoTransform, !SoUnits
#if defined(COIN_EXCLUDE_SOTRANSFORMATION) // (AUTOGEN)
#define COIN_EXCLUDE_SOANTISQUISH 1
#define COIN_EXCLUDE_SOMATRIXTRANSFORM 1
#define COIN_EXCLUDE_SOROTATION 1
#define COIN_EXCLUDE_SORESETTRANSFORM 1
#define COIN_EXCLUDE_SOROTATIONXYZ 1
#define COIN_EXCLUDE_SOSCALE 1
#define COIN_EXCLUDE_SOSURROUNDSCALE 1
#define COIN_EXCLUDE_SOTRANSLATION 1
#define COIN_EXCLUDE_SOTRANSFORM 1
#define COIN_EXCLUDE_SOUNITS 1
#endif // COIN_EXCLUDE_SOTRANSFORMATION  (AUTOGEN)

//# !SoCamera: !SoPerspectiveCamera, !SoOrthographicCamera
#if defined(COIN_EXCLUDE_SOCAMERA) // (AUTOGEN)
#define COIN_EXCLUDE_SOPERSPECTIVECAMERA 1
#define COIN_EXCLUDE_SOORTHOGRAPHICCAMERA 1
#endif // COIN_EXCLUDE_SOCAMERA  (AUTOGEN)

//# !SoPointSet: !SoMarkerSet
#if defined(COIN_EXCLUDE_SOPOINTSET) // (AUTOGEN)
#define COIN_EXCLUDE_SOMARKERSET 1
#endif // COIN_EXCLUDE_SOPOINTSET  (AUTOGEN)

//# !SoIndexedShape: !SoIndexedFaceSet, !SoIndexedLineSet,
//#   !SoIndexedTriangleStripSet
#if defined(COIN_EXCLUDE_SOINDEXEDSHAPE) // (AUTOGEN)
#define COIN_EXCLUDE_SOINDEXEDFACESET 1
#define COIN_EXCLUDE_SOINDEXEDLINESET 1
#define COIN_EXCLUDE_SOINDEXEDTRIANGLESTRIPSET 1
#endif // COIN_EXCLUDE_SOINDEXEDSHAPE  (AUTOGEN)

//# !SoSelection: !SoExtSelection
#if defined(COIN_EXCLUDE_SOSELECTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOEXTSELECTION 1
#endif // COIN_EXCLUDE_SOSELECTION  (AUTOGEN)

//# !SoLocateHighlight: !SoWWWAnchor
#if defined(COIN_EXCLUDE_SOLOCATEHIGHLIGHT) // (AUTOGEN)
#define COIN_EXCLUDE_SOWWWANCHOR 1
#endif // COIN_EXCLUDE_SOLOCATEHIGHLIGHT  (AUTOGEN)

//# !SoRotation: !SoPendulum, !SoRotor
#if defined(COIN_EXCLUDE_SOROTATION) // (AUTOGEN)
#define COIN_EXCLUDE_SOPENDULUM 1
#define COIN_EXCLUDE_SOROTOR 1
#endif // COIN_EXCLUDE_SOROTATION  (AUTOGEN)

//# !SoTranslation, !SoShuttle
#if defined(COIN_EXCLUDE_SOTRANSLATION) // (AUTOGEN)
#define COIN_EXCLUDE_SOSHUTTLE 1
#endif // COIN_EXCLUDE_SOTRANSLATION  (AUTOGEN)

//# !SoLight: !SoDirectionalLight, !SoSpotLight, !SoPointLight
#if defined(COIN_EXCLUDE_SOLIGHT) // (AUTOGEN)
#define COIN_EXCLUDE_SODIRECTIONALLIGHT 1
#define COIN_EXCLUDE_SOSPOTLIGHT 1
#define COIN_EXCLUDE_SOPOINTLIGHT 1
#endif // COIN_EXCLUDE_SOLIGHT  (AUTOGEN)

//# !SoFont: !SoFontStyle
#if defined(COIN_EXCLUDE_SOFONT) // (AUTOGEN)
#define COIN_EXCLUDE_SOFONTSTYLE 1
#endif // COIN_EXCLUDE_SOFONT  (AUTOGEN)

//# !SoProfile: !SoLinearProfile, !SoNurbsProfile
#if defined(COIN_EXCLUDE_SOPROFILE) // (AUTOGEN)
#define COIN_EXCLUDE_SOLINEARPROFILE 1
#define COIN_EXCLUDE_SONURBSPROFILE 1
#endif // COIN_EXCLUDE_SOPROFILE  (AUTOGEN)

//# !SoTextureCoordinateFunction: !SoTextureCoordinateDefault,
//#   !SoTextureCoordinateEnvironment, !SoTextureCoordinatePlane
#if defined(COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOTEXTURECOORDINATEDEFAULT 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEENVIRONMENT 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE 1
#endif // COIN_EXCLUDE_SOTEXTURECOORDINATEFUNCTION  (AUTOGEN)



///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Actions' dependency rules                                 //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

//# !SoAction: !SoCallbackAction, !SoGLRenderAction, !SoGetBoundingBoxAction,
//#   !SoGetMatrixAction, !SoGetPrimitiveCountAction, !SoHandleEventAction,
//#   !SoPickAction, !SoSearchAction, !SoSimplifyAction, !SoToVRMLAction,
//#   !SoWriteAction, 
#if defined(COIN_EXCLUDE_SOACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOCALLBACKACTION 1
#define COIN_EXCLUDE_SOGLRENDERACTION 1
#define COIN_EXCLUDE_SOGETBOUNDINGBOXACTION 1
#define COIN_EXCLUDE_SOGETMATRIXACTION 1
#define COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION 1
#define COIN_EXCLUDE_SOHANDLEEVENTACTION 1
#define COIN_EXCLUDE_SOPICKACTION 1
#define COIN_EXCLUDE_SOSEARCHACTION 1
#define COIN_EXCLUDE_SOSIMPLIFYACTION 1
#define COIN_EXCLUDE_SOTOVRMLACTION 1
#define COIN_EXCLUDE_SOWRITEACTION 1
#endif // COIN_EXCLUDE_SOACTION  (AUTOGEN)

//# !SoGLRenderAction:
//#   !SoBoxHighlightRenderaction,
//#   !SoLineHighlightRenderaction
#if defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOBOXHIGHLIGHTRENDERACTION 1
#define COIN_EXCLUDE_SOLINEHIGHLIGHTRENDERACTION 1
#endif // COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)

//# !SoPickAction: !SoRayPickAction
#if defined(COIN_EXCLUDE_SOPICKACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SORAYPICKACTION 1
#endif // COIN_EXCLUDE_SOPICKACTION  (AUTOGEN)

//# !SoSimplifyAction: !SoGlobalSimplifyAction, !SoReorganizeAction,
//#   !SoShapeSimplifyAction, 
#if defined(COIN_EXCLUDE_SOSIMPLIFYACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOGLOBALSIMPLIFYACTION 1
#define COIN_EXCLUDE_SOREORGANIZEACTION 1
#define COIN_EXCLUDE_SOSHAPESIMPLIFYACTION 1
#endif // COIN_EXCLUDE_SOSIMPLIFYACTION  (AUTOGEN)

//# !SoToVRMLAction: !SoToVRML2Action
#if defined(COIN_EXCLUDE_SOTOVRMLACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOTOVRML2ACTION 1
#endif // COIN_EXCLUDE_SOTOVRMLACTION  (AUTOGEN)



///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Bundles' dependency rules                                 //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

// If there are no actions, there shouldn't be any need for bundles
// either.
//# !SoAction: !SoBundle
#if defined(COIN_EXCLUDE_SOACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOBUNDLE 1
#endif // COIN_EXCLUDE_SOACTION  (AUTOGEN)

// FIXME: there should be more fine-grained dependency rules here,
// based on the presence of normal, material and texture element
// settings. 19990408 mortene.
//# !SoGLRenderAction: !SoNormalbundle, !SoMaterialbundle,
//#   !SoTexturecoordinatebundle, 
#if defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SONORMALBUNDLE 1
#define COIN_EXCLUDE_SOMATERIALBUNDLE 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEBUNDLE 1
#endif // COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)

//# !SoBundle: !SoNormalbundle, !SoMaterialbundle, !SoTexturecoordinatebundle
#if defined(COIN_EXCLUDE_SOBUNDLE) // (AUTOGEN)
#define COIN_EXCLUDE_SONORMALBUNDLE 1
#define COIN_EXCLUDE_SOMATERIALBUNDLE 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEBUNDLE 1
#endif // COIN_EXCLUDE_SOBUNDLE  (AUTOGEN)



///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Elements' dependency rules                                //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

// The default state for an element should be off, so we start by
// configuring all elements out of the make process.
#define COIN_EXCLUDE_SOELEMENT 1
#define COIN_EXCLUDE_SOACCUMULATEDELEMENT 1
#define COIN_EXCLUDE_SOCLIPPLANEELEMENT 1
#define COIN_EXCLUDE_SOGLCLIPPLANEELEMENT 1
#define COIN_EXCLUDE_SOLIGHTELEMENT 1
#define COIN_EXCLUDE_SOMODELMATRIXELEMENT 1
#define COIN_EXCLUDE_SOBBOXMODELMATRIXELEMENT 1
#define COIN_EXCLUDE_SOGLMODELMATRIXELEMENT 1
#define COIN_EXCLUDE_SOPROFILEELEMENT 1
#define COIN_EXCLUDE_SOTEXTUREMATRIXELEMENT 1
#define COIN_EXCLUDE_SOGLTEXTUREMATRIXELEMENT 1
#define COIN_EXCLUDE_SOCACHEELEMENT 1
#define COIN_EXCLUDE_SOINT32ELEMENT 1
#define COIN_EXCLUDE_SOANNOTEXT3CHARORIENTELEMENT 1
#define COIN_EXCLUDE_SOANNOTEXT3FONTSIZEHINTELEMENT 1
#define COIN_EXCLUDE_SOANNOTEXT3RENDERPRINTELEMENT 1
#define COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT 1
#define COIN_EXCLUDE_SODECIMATIONTYPEELEMENT 1
#define COIN_EXCLUDE_SODRAWSTYLEELEMENT 1
#define COIN_EXCLUDE_SOGLDRAWSTYLEELEMENT 1
#define COIN_EXCLUDE_SOGLLIGHTIDELEMENT 1
#define COIN_EXCLUDE_SOGLTEXTUREENABLEDELEMENT 1
#define COIN_EXCLUDE_SOLINEPATTERNELEMENT 1
#define COIN_EXCLUDE_SOGLLINEPATTERNELEMENT 1
#define COIN_EXCLUDE_SOMATERIALBINDINGELEMENT 1
#define COIN_EXCLUDE_SONORMALBINDINGELEMENT 1
#define COIN_EXCLUDE_SOPICKSTYLEELEMENT 1
#define COIN_EXCLUDE_SOSWITCHELEMENT 1
#define COIN_EXCLUDE_SOTEXTOUTLINEENABLEDELEMENT 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEBINDINGELEMENT 1
#define COIN_EXCLUDE_SOUNITSELEMENT 1
#define COIN_EXCLUDE_SOFLOATELEMENT 1
#define COIN_EXCLUDE_SOCOMPLEXITYELEMENT 1
#define COIN_EXCLUDE_SOCREASEANGLEELEMENT 1
#define COIN_EXCLUDE_SODECIMATIONPERCENTAGEELEMENT 1
#define COIN_EXCLUDE_SOFOCALDISTANCEELEMENT 1
#define COIN_EXCLUDE_SOFONTSIZEELEMENT 1
#define COIN_EXCLUDE_SOLINEWIDTHELEMENT 1
#define COIN_EXCLUDE_SOGLLINEWIDTHELEMENT 1
#define COIN_EXCLUDE_SOPOINTSIZEELEMENT 1
#define COIN_EXCLUDE_SOGLPOINTSIZEELEMENT 1
#define COIN_EXCLUDE_SOTEXTUREQUALITYELEMENT 1
#define COIN_EXCLUDE_SOTEXTUREOVERRIDEELEMENT 1
#define COIN_EXCLUDE_SOGLCACHECONTEXTELEMENT 1
#define COIN_EXCLUDE_SOGLRENDERPASSELEMENT 1
#define COIN_EXCLUDE_SOGLUPDATEAREAELEMENT 1
#define COIN_EXCLUDE_SOLAZYELEMENT 1
#define COIN_EXCLUDE_SOGLLAZYELEMENT 1
#define COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT 1
#define COIN_EXCLUDE_SOOVERRIDEELEMENT 1
#define COIN_EXCLUDE_SOPICKRAYELEMENT 1
#define COIN_EXCLUDE_SOREPLACEDELEMENT 1
#define COIN_EXCLUDE_SOCOORDINATEELEMENT 1
#define COIN_EXCLUDE_SOGLCOORDINATEELEMENT 1
#define COIN_EXCLUDE_SOENVIRONMENTELEMENT 1
#define COIN_EXCLUDE_SOGLENVIRONMENTELEMENT 1
#define COIN_EXCLUDE_SOFONTNAMEELEMENT 1
#define COIN_EXCLUDE_SOLIGHTATTENUATIONELEMENT 1
#define COIN_EXCLUDE_SONORMALELEMENT 1
#define COIN_EXCLUDE_SOGLNORMALELEMENT 1
#define COIN_EXCLUDE_SOPOLYGONOFFSETELEMENT 1
#define COIN_EXCLUDE_SOGLPOLYGONOFFSETELEMENT 1
#define COIN_EXCLUDE_SOPROJECTIONMATRIXELEMENT 1
#define COIN_EXCLUDE_SOGLPROJECTIONMATRIXELEMENT 1
#define COIN_EXCLUDE_SOPROFILECOORDINATEELEMENT 1
#define COIN_EXCLUDE_SOTEXTURECOORDINATEELEMENT 1
#define COIN_EXCLUDE_SOGLTEXTURECOORDINATEELEMENT 1
#define COIN_EXCLUDE_SOTEXTUREIMAGEELEMENT 1
#define COIN_EXCLUDE_SOGLTEXTUREIMAGEELEMENT 1
#define COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT 1
#define COIN_EXCLUDE_SOGLVIEWINGMATRIXELEMENT 1
#define COIN_EXCLUDE_SOVIEWVOLUMEELEMENT 1
#define COIN_EXCLUDE_SOSHAPEHINTSELEMENT 1
#define COIN_EXCLUDE_SOGLSHAPEHINTSELEMENT 1
#define COIN_EXCLUDE_SOSHAPESTYLEELEMENT 1
#define COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT 1
#define COIN_EXCLUDE_SOGLVIEWPORTREGIONELEMENT 1
#define COIN_EXCLUDE_SOWINDOWELEMENT 1
#define COIN_EXCLUDE_SOAMBIENTCOLORELEMENT 1
#define COIN_EXCLUDE_SOEMISSIVECOLORELEMENT 1
#define COIN_EXCLUDE_SOLIGHTMODELELEMENT 1
#define COIN_EXCLUDE_SOGLLIGHTMODELELEMENT 1
#define COIN_EXCLUDE_SOSHININESSELEMENT 1
#define COIN_EXCLUDE_SOSPECULARCOLORELEMENT 1
#define COIN_EXCLUDE_SOTRANSPARENCYELEMENT 1
#define COIN_EXCLUDE_SODIFFUSECOLORELEMENT 1
#define COIN_EXCLUDE_SOGLAMBIENTCOLORELEMENT 1
#define COIN_EXCLUDE_SOGLPOLYGONSTIPPLEELEMENT 1
#define COIN_EXCLUDE_SOGLCOLORINDEXELEMENT 1
#define COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT 1
#define COIN_EXCLUDE_SOGLDISPLAYLIST 1
#define COIN_EXCLUDE_SOGLSHININESSELEMENT 1
#define COIN_EXCLUDE_SOGLSPECULARCOLORELEMENT 1
#define COIN_EXCLUDE_SOGLEMISSIVECOLORELEMENT 1
#define COIN_EXCLUDE_SOGLSHADEMODELELEMENT 1

////////////////////////////////////////////////////////////
// Action class dependencies on elements.                 //
////////////////////////////////////////////////////////////

//# SoAction: SoOverrideElement
#if !defined(COIN_EXCLUDE_SOACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOOVERRIDEELEMENT
#endif // !COIN_EXCLUDE_SOACTION  (AUTOGEN)

//# SoGLRenderAction:
//#   SoGLLazyElement, SoViewportRegionElement, SoGLRenderPassElement,
//#   SoDecimationTypeElement, SoDecimationPercentageElement, SoWindowElement,
//#   SoGLLightIdElement, SoGLUpdateAreaElement, SoGLViewportRegionElement,
//#   SoTextureOverrideElement, SoGLNormalizeElement, SoGLShadeModelElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLLAZYELEMENT
#undef COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT
#undef COIN_EXCLUDE_SOGLRENDERPASSELEMENT
#undef COIN_EXCLUDE_SODECIMATIONTYPEELEMENT
#undef COIN_EXCLUDE_SODECIMATIONPERCENTAGEELEMENT
#undef COIN_EXCLUDE_SOWINDOWELEMENT
#undef COIN_EXCLUDE_SOGLLIGHTIDELEMENT
#undef COIN_EXCLUDE_SOGLUPDATEAREAELEMENT
#undef COIN_EXCLUDE_SOGLVIEWPORTREGIONELEMENT
#undef COIN_EXCLUDE_SOTEXTUREOVERRIDEELEMENT
#undef COIN_EXCLUDE_SOGLNORMALIZEELEMENT
#undef COIN_EXCLUDE_SOGLSHADEMODELELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)

//# SoGetBoundingBoxAction: SoViewportRegionElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)


////////////////////////////////////////////////////////////
// Node class dependencies on elements.                   //
////////////////////////////////////////////////////////////


#if !defined(COIN_EXCLUDE_SOCAMERA)
//# SoGLRenderAction: SoFocalDistanceElement, SoGLProjectionMatrixElement,
//#   SoViewVolumeElement, SoGLViewingMatrixElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOFOCALDISTANCEELEMENT
#undef COIN_EXCLUDE_SOGLPROJECTIONMATRIXELEMENT
#undef COIN_EXCLUDE_SOVIEWVOLUMEELEMENT
#undef COIN_EXCLUDE_SOGLVIEWINGMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)

//# SoGetBoundingBoxAction: SoFocalDistanceElement, SoProjectionMatrixElement,
//#   SoViewVolumeElement, SoViewingMatrixElement, 
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOFOCALDISTANCEELEMENT
#undef COIN_EXCLUDE_SOPROJECTIONMATRIXELEMENT
#undef COIN_EXCLUDE_SOVIEWVOLUMEELEMENT
#undef COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)
#endif // COIN_EXCLUDE_SOCAMERA

//# SoSwitch: SoSwitchElement
#if !defined(COIN_EXCLUDE_SOSWITCH) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSWITCHELEMENT
#endif // !COIN_EXCLUDE_SOSWITCH  (AUTOGEN)

#if !defined(COIN_EXCLUDE_SOTRANSFORMATION)
//# SoGetBoundingBoxAction: SoModelMatrixElement, SoBBoxModelMatrixElement, SoLocalBBoxMatrixElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMODELMATRIXELEMENT
#undef COIN_EXCLUDE_SOBBOXMODELMATRIXELEMENT
#undef COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoGLModelMatrixElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLMODELMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // COIN_EXCLUDE_SOTRANSFORMATION

#if !defined(COIN_EXCLUDE_SOCOORDINATE3)
//# SoGetBoundingBoxAction: SoCoordinateElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoGLCoordinateElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLCOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // COIN_EXCLUDE_SOCOORDINATE3

//# SoShapeHints: SoShapehintsElement
#if !defined(COIN_EXCLUDE_SOSHAPEHINTS) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSHAPEHINTSELEMENT
#endif // !COIN_EXCLUDE_SOSHAPEHINTS  (AUTOGEN)

//# SoTextureCoordinate2: SoTexturecoordinateElement
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATE2) // (AUTOGEN)
#undef COIN_EXCLUDE_SOTEXTURECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATE2  (AUTOGEN)

#if !defined(COIN_EXCLUDE_SOANNOTEXT3PROPERTY)
//# SoGLRenderAction: SoAnnoText3FontSizeHintElement,
//#   SoAnnoText3RenderPrintElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOANNOTEXT3FONTSIZEHINTELEMENT
#undef COIN_EXCLUDE_SOANNOTEXT3RENDERPRINTELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)

//# SoGetBoundingBoxAction: SoAnnoText3FontSizeHintElement,
//#   SoAnnoText3RenderPrintElement, 
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOANNOTEXT3FONTSIZEHINTELEMENT
#undef COIN_EXCLUDE_SOANNOTEXT3RENDERPRINTELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOANNOTEXT3PROPERTY

#if !defined(COIN_EXCLUDE_SOSEPARATOR)
//# SoGetBoundingBoxAction: SoCacheElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCACHEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoCacheElement, SoGLCacheContextElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCACHEELEMENT
#undef COIN_EXCLUDE_SOGLCACHECONTEXTELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOSEPARATOR

#if !defined(COIN_EXCLUDE_SOUNITS)
//# SoGetBoundingBoxAction: SoUnitsElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOUNITSELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoUnitsElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOUNITSELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOUNITS

#if !defined(COIN_EXCLUDE_SOBASECOLOR)
//# SoGLRenderAction: SoGLDiffuseColorElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOBASECOLOR

#if !defined(COIN_EXCLUDE_SOPACKEDCOLOR)
//# SoGLRenderAction: SoGLDiffuseColorElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOPACKEDCOLOR

#if !defined(COIN_EXCLUDE_SOCLIPPLANE)
//# SoGLRenderAction: SoGLClipPlaneElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLCLIPPLANEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOCLIPPLANE

#if !defined(COIN_EXCLUDE_SOCOMPLEXITY)
//# SoGetBoundingBoxAction: SoComplexityElement, SoComplexityTypeElement,
//#   SoShapeStyleElement, 
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCOMPLEXITYELEMENT
#undef COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT
#undef COIN_EXCLUDE_SOSHAPESTYLEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoComplexityElement, SoComplexityTypeElement,
//#   SoShapeStyleElement, SoTextureQualityElement, SoTextureOverrideElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCOMPLEXITYELEMENT
#undef COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT
#undef COIN_EXCLUDE_SOSHAPESTYLEELEMENT
#undef COIN_EXCLUDE_SOTEXTUREQUALITYELEMENT
#undef COIN_EXCLUDE_SOTEXTUREOVERRIDEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOCOMPLEXITY

#if !defined(COIN_EXCLUDE_SOLIGHT)
//# SoGLRenderAction: SoLightAttenuationElement, SoGLLightIdElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOLIGHTATTENUATIONELEMENT
#undef COIN_EXCLUDE_SOGLLIGHTIDELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOLIGHT

#if !defined(COIN_EXCLUDE_SODRAWSTYLE)
//# SoGLRenderAction: SoGLDrawStyleElement, SoShapeStyleElement,
//#   SoGLLinePatternElement, SoGLLineWidthElement, SoGLPointSizeElement,
//#   SoGLPolygonStippleElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLDRAWSTYLEELEMENT
#undef COIN_EXCLUDE_SOSHAPESTYLEELEMENT
#undef COIN_EXCLUDE_SOGLLINEPATTERNELEMENT
#undef COIN_EXCLUDE_SOGLLINEWIDTHELEMENT
#undef COIN_EXCLUDE_SOGLPOINTSIZEELEMENT
#undef COIN_EXCLUDE_SOGLPOLYGONSTIPPLEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SODRAWSTYLE

#if !defined(COIN_EXCLUDE_SOFONT)
//# SoGetBoundingBoxAction: SoFontNameElement, SoFontSizeElement, 
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOFONTNAMEELEMENT
#undef COIN_EXCLUDE_SOFONTSIZEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoFontNameElement, SoFontSizeElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOFONTNAMEELEMENT
#undef COIN_EXCLUDE_SOFONTSIZEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOFONT

#if !defined(COIN_EXCLUDE_SOLIGHTMODEL)
//# SoGLRenderAction: SoGLLightModelElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLLIGHTMODELELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOLIGHTMODEL

#if !defined(COIN_EXCLUDE_SOENVIRONMENT)
//# SoGLRenderAction: SoGLEnvironmentElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLENVIRONMENTELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOENVIRONMENT

#if !defined(COIN_EXCLUDE_SOPROFILE)
//# SoGetBoundingBoxAction: SoProfileElement, SoProfileCoordinateElement, 
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOPROFILEELEMENT
#undef COIN_EXCLUDE_SOPROFILECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoProfileElement, SoProfileCoordinateElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOPROFILEELEMENT
#undef COIN_EXCLUDE_SOPROFILECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOPROFILE

#if !defined(COIN_EXCLUDE_SOMATERIAL)
//# SoGLRenderAction: SoGLAmbientColorElement, SoGLDiffuseColorElement,
//#   SoGLEmissiveColorElement, SoGLSpecularColorElement, SoGLShininessElement,
//#   SoTransparencyElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLAMBIENTCOLORELEMENT
#undef COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT
#undef COIN_EXCLUDE_SOGLEMISSIVECOLORELEMENT
#undef COIN_EXCLUDE_SOGLSPECULARCOLORELEMENT
#undef COIN_EXCLUDE_SOGLSHININESSELEMENT
#undef COIN_EXCLUDE_SOTRANSPARENCYELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOMATERIAL

#if !defined(COIN_EXCLUDE_SOMATERIALBINDING)
//# SoGLRenderAction: SoMaterialBindingElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMATERIALBINDINGELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOMATERIALBINDING

#if !defined(COIN_EXCLUDE_SOPICKSTYLE)
//# SoPickAction:: SoPickStyleElement
#if !defined(COIN_EXCLUDE_SOPICKACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOPICKSTYLEELEMENT
#endif // !COIN_EXCLUDE_SOPICKACTION  (AUTOGEN)
#endif // ! COIN_EXCLUDE_SOPICKSTYLE

#if !defined(COIN_EXCLUDE_SONORMAL)
//# SoGLRenderAction: SoGLNormalElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLNORMALELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SONORMAL

#if !defined(COIN_EXCLUDE_SONORMALBINDING)
//# SoGLRenderAction: SoNormalBindingElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SONORMALBINDINGELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SONORMALBINDING

#if !defined(COIN_EXCLUDE_SOPOLYGONOFFSET)
//# SoGLRenderAction: SoGLPolygonOffsetElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLPOLYGONOFFSETELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOPOLYGONOFFSET

#if !defined(COIN_EXCLUDE_SOSHAPEHINTS)
//# SoGetBoundingBoxAction: SoShapeHintsElement, SoCreaseAngleElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSHAPEHINTSELEMENT
#undef COIN_EXCLUDE_SOCREASEANGLEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoGLShapeHintsElement, SoCreaseAngleElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLSHAPEHINTSELEMENT
#undef COIN_EXCLUDE_SOCREASEANGLEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOSHAPEHINTS

#if !defined(COIN_EXCLUDE_SOTEXTURE2)
//# SoGLRenderAction: SoGLTextureImageElement, SoTextureOverrideElement,
//#   SoGLTextureEnabledElement, 
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLTEXTUREIMAGEELEMENT
#undef COIN_EXCLUDE_SOTEXTUREOVERRIDEELEMENT
#undef COIN_EXCLUDE_SOGLTEXTUREENABLEDELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOTEXTURE2

#if !defined(COIN_EXCLUDE_SOTEXTURE2TRANSFORM)
//# SoGLRenderAction: SoGLTextureMatrixElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLTEXTUREMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOTEXTURE2TRANSFORM

#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATE2)
//# SoGLRenderAction: SoGLTextureCoordinateElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLTEXTURECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATE2

#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING)
//# SoGLRenderAction: SoTextureCoordinateBindingElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOTEXTURECOORDINATEBINDINGELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING

#if !defined(COIN_EXCLUDE_SOVERTEXPROPERTY)
//# SoGetBoundingBoxAction: SoCoordinateElement
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOCOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION  (AUTOGEN)

//# SoGLRenderAction: SoGLCoordinateElement, SoMaterialBindingElement,
//#   SoNormalBindingElement, SoGLNormalElement, SoGLTextureCoordinateElement
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOGLCOORDINATEELEMENT
#undef COIN_EXCLUDE_SOMATERIALBINDINGELEMENT
#undef COIN_EXCLUDE_SONORMALBINDINGELEMENT
#undef COIN_EXCLUDE_SOGLNORMALELEMENT
#undef COIN_EXCLUDE_SOGLTEXTURECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERACTION  (AUTOGEN)
#endif // !COIN_EXCLUDE_SOVERTEXPROPERTY

//////////////////////////////////////////////////////////////////////
// Subclass -> superclass and other dependencies among elements.    //
//////////////////////////////////////////////////////////////////////

#if !defined(COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT)
#undef COIN_EXCLUDE_SODIFFUSECOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLDIFFUSECOLORELEMENT
#if !defined(COIN_EXCLUDE_SOGLAMBIENTCOLORELEMENT)
#undef COIN_EXCLUDE_SOAMBIENTCOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLAMBIENTCOLORELEMENT
#if !defined(COIN_EXCLUDE_SOGLEMISSIVECOLORELEMENT)
#undef COIN_EXCLUDE_SOEMISSIVECOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLEMISSIVECOLORELEMENT
#if !defined(COIN_EXCLUDE_SOGLSHININESSELEMENT)
#undef COIN_EXCLUDE_SOSHININESSELEMENT
#endif // !COIN_EXCLUDE_SOGLSHININESSELEMENT
#if !defined(COIN_EXCLUDE_SOGLSPECULARCOLORELEMENT)
#undef COIN_EXCLUDE_SOSPECULARCOLORELEMENT
#endif // !COIN_EXCLUDE_SOGLSPECULARCOLORELEMENT
#if !defined(COIN_EXCLUDE_SOOVERRIDEELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOOVERRIDEELEMENT
#if !defined(COIN_EXCLUDE_SOGLCLIPPLANEELEMENT)
#undef COIN_EXCLUDE_SOCLIPPLANEELEMENT
#endif // !COIN_EXCLUDE_SOGLCLIPPLANEELEMENT
#if !defined(COIN_EXCLUDE_SOBBOXMODELMATRIXELEMENT)
#undef COIN_EXCLUDE_SOMODELMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOBBOXMODELMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOGLMODELMATRIXELEMENT)
#undef COIN_EXCLUDE_SOMODELMATRIXELEMENT
#undef COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLMODELMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOGLTEXTUREMATRIXELEMENT)
#undef COIN_EXCLUDE_SOTEXTUREMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLTEXTUREMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOGLDRAWSTYLEELEMENT)
#undef COIN_EXCLUDE_SODRAWSTYLEELEMENT
#endif // !COIN_EXCLUDE_SOGLDRAWSTYLEELEMENT
#if !defined(COIN_EXCLUDE_SOGLLINEPATTERNELEMENT)
#undef COIN_EXCLUDE_SOLINEPATTERNELEMENT
#endif // !COIN_EXCLUDE_SOGLLINEPATTERNELEMENT
#if !defined(COIN_EXCLUDE_SOGLVIEWPORTREGIONELEMENT)
#undef COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT
#endif // !COIN_EXCLUDE_SOGLVIEWPORTREGIONELEMENT
#if !defined(COIN_EXCLUDE_SOGLSHAPEHINTSELEMENT)
#undef COIN_EXCLUDE_SOSHAPEHINTSELEMENT
#endif // !COIN_EXCLUDE_SOGLSHAPEHINTSELEMENT
#if !defined(COIN_EXCLUDE_SOGLLAZYELEMENT)
#undef COIN_EXCLUDE_SOLAZYELEMENT
#endif // !COIN_EXCLUDE_SOGLLAZYELEMENT
#if !defined(COIN_EXCLUDE_SOGLCOORDINATEELEMENT)
#undef COIN_EXCLUDE_SOCOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLCOORDINATEELEMENT
#if !defined(COIN_EXCLUDE_SOCLIPPLANEELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOCLIPPLANEELEMENT
#if !defined(COIN_EXCLUDE_SOLIGHTELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOLIGHTELEMENT
#if !defined(COIN_EXCLUDE_SOMODELMATRIXELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOMODELMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOPROFILEELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOPROFILEELEMENT
#if !defined(COIN_EXCLUDE_SOPROFILEELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOPROFILEELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTUREMATRIXELEMENT)
#undef COIN_EXCLUDE_SOACCUMULATEDELEMENT
#endif // !COIN_EXCLUDE_SOTEXTUREMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOACCUMULATEDELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOACCUMULATEDELEMENT
#if !defined(COIN_EXCLUDE_SOCACHEELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOCACHEELEMENT
#if !defined(COIN_EXCLUDE_SOANNOTEXT3CHARORIENTELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOANNOTEXT3CHARORIENTELEMENT
#if !defined(COIN_EXCLUDE_SOANNOTEXT3FONTSIZEHINTELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOANNOTEXT3FONTSIZEHINTELEMENT
#if !defined(COIN_EXCLUDE_SOANNOTEXT3RENDERPRINTELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOANNOTEXT3RENDERPRINTELEMENT
#if !defined(COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT
#if !defined(COIN_EXCLUDE_SODECIMATIONTYPEELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SODECIMATIONTYPEELEMENT
#if !defined(COIN_EXCLUDE_SODRAWSTYLEELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SODRAWSTYLEELEMENT
#if !defined(COIN_EXCLUDE_SOGLLIGHTIDELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOGLLIGHTIDELEMENT
#if !defined(COIN_EXCLUDE_SOGLTEXTUREENABLEDELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOGLTEXTUREENABLEDELEMENT
#if !defined(COIN_EXCLUDE_SOGLLIGHTMODELELEMENT)
#undef COIN_EXCLUDE_SOLIGHTMODELELEMENT
#endif // !COIN_EXCLUDE_SOGLLIGHTMODELELEMENT
#if !defined(COIN_EXCLUDE_SOLIGHTMODELELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOLIGHTMODELELEMENT
#if !defined(COIN_EXCLUDE_SOLINEPATTERNELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOLINEPATTERNELEMENT
#if !defined(COIN_EXCLUDE_SOMATERIALBINDINGELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOMATERIALBINDINGELEMENT
#if !defined(COIN_EXCLUDE_SONORMALBINDINGELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SONORMALBINDINGELEMENT
#if !defined(COIN_EXCLUDE_SOPICKSTYLEELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOPICKSTYLEELEMENT
#if !defined(COIN_EXCLUDE_SOSWITCHELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOSWITCHELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTOUTLINEENABLEDELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOTEXTOUTLINEENABLEDELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEBINDINGELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATEBINDINGELEMENT
#if !defined(COIN_EXCLUDE_SOUNITSELEMENT)
#undef COIN_EXCLUDE_SOINT32ELEMENT
#endif // !COIN_EXCLUDE_SOUNITSELEMENT
#if !defined(COIN_EXCLUDE_SOINT32ELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOINT32ELEMENT
#if !defined(COIN_EXCLUDE_SOCOMPLEXITYELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOCOMPLEXITYELEMENT
#if !defined(COIN_EXCLUDE_SOCREASEANGLEELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOCREASEANGLEELEMENT
#if !defined(COIN_EXCLUDE_SODECIMATIONPERCENTAGEELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SODECIMATIONPERCENTAGEELEMENT
#if !defined(COIN_EXCLUDE_SOFOCALDISTANCEELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOFOCALDISTANCEELEMENT
#if !defined(COIN_EXCLUDE_SOFONTSIZEELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOFONTSIZEELEMENT
#if !defined(COIN_EXCLUDE_SOGLLINEWIDTHELEMENT)
#undef COIN_EXCLUDE_SOLINEWIDTHELEMENT
#endif // !COIN_EXCLUDE_SOGLLINEWIDTHELEMENT
#if !defined(COIN_EXCLUDE_SOGLENVIRONMENTELEMENT)
#undef COIN_EXCLUDE_SOENVIRONMENTELEMENT
#endif // ! COIN_EXCLUDE_SOGLENVIRONMENTELEMENT
#if !defined(COIN_EXCLUDE_SOLINEWIDTHELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOLINEWIDTHELEMENT
#if !defined(COIN_EXCLUDE_SOGLPOINTSIZEELEMENT)
#undef COIN_EXCLUDE_SOPOINTSIZEELEMENT
#endif // !COIN_EXCLUDE_SOGLPOINTSIZEELEMENT
#if !defined(COIN_EXCLUDE_SOPOINTSIZEELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOPOINTSIZEELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTUREQUALITYELEMENT)
#undef COIN_EXCLUDE_SOFLOATELEMENT
#endif // !COIN_EXCLUDE_SOTEXTUREQUALITYELEMENT
#if !defined(COIN_EXCLUDE_SOFLOATELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOFLOATELEMENT
#if !defined(COIN_EXCLUDE_SOGLCACHECONTEXTELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOGLCACHECONTEXTELEMENT
#if !defined(COIN_EXCLUDE_SOGLRENDERPASSELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOGLRENDERPASSELEMENT
#if !defined(COIN_EXCLUDE_SOGLUPDATEAREAELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOGLUPDATEAREAELEMENT
#if !defined(COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOOVERRIDEELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOOVERRIDEELEMENT
#if !defined(COIN_EXCLUDE_SOPICKRAYELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOPICKRAYELEMENT
#if !defined(COIN_EXCLUDE_SOAMBIENTCOLORELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOAMBIENTCOLORELEMENT
#if !defined(COIN_EXCLUDE_SOCOORDINATEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOCOORDINATEELEMENT
#if !defined(COIN_EXCLUDE_SOEMISSIVECOLORELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOEMISSIVECOLORELEMENT
#if !defined(COIN_EXCLUDE_SOENVIRONMENTELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOENVIRONMENTELEMENT
#if !defined(COIN_EXCLUDE_SOFONTNAMEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOFONTNAMEELEMENT
#if !defined(COIN_EXCLUDE_SOLIGHTATTENUATIONELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOLIGHTATTENUATIONELEMENT
#if !defined(COIN_EXCLUDE_SOGLNORMALELEMENT)
#undef COIN_EXCLUDE_SONORMALELEMENT
#endif // !COIN_EXCLUDE_SOGLNORMALELEMENT
#if !defined(COIN_EXCLUDE_SONORMALELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SONORMALELEMENT
#if !defined(COIN_EXCLUDE_SOGLPOLYGONOFFSETELEMENT)
#undef COIN_EXCLUDE_SOPOLYGONOFFSETELEMENT
#endif // !COIN_EXCLUDE_SOGLPOLYGONOFFSETELEMENT
#if !defined(COIN_EXCLUDE_SOPOLYGONOFFSETELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOPOLYGONOFFSETELEMENT
#if !defined(COIN_EXCLUDE_SOGLPROJECTIONMATRIXELEMENT)
#undef COIN_EXCLUDE_SOPROJECTIONMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLPROJECTIONMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOPROJECTIONMATRIXELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOPROJECTIONMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOPROFILECOORDINATEELEMENT
#if !defined(COIN_EXCLUDE_SOSHININESSELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOSHININESSELEMENT
#if !defined(COIN_EXCLUDE_SOSPECULARCOLORELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOSPECULARCOLORELEMENT
#if !defined(COIN_EXCLUDE_SOGLTEXTURECOORDINATEELEMENT)
#undef COIN_EXCLUDE_SOTEXTURECOORDINATEELEMENT
#endif // !COIN_EXCLUDE_SOGLTEXTURECOORDINATEELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATEELEMENT
#if !defined(COIN_EXCLUDE_SOGLTEXTUREIMAGEELEMENT)
#undef COIN_EXCLUDE_SOTEXTUREIMAGEELEMENT
#endif // !COIN_EXCLUDE_SOGLTEXTUREIMAGEELEMENT
#if !defined(COIN_EXCLUDE_SOTEXTUREIMAGEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOTEXTUREIMAGEELEMENT
#if !defined(COIN_EXCLUDE_SOGLVIEWINGMATRIXELEMENT)
#undef COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT
#endif // !COIN_EXCLUDE_SOGLVIEWINGMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOVIEWINGMATRIXELEMENT
#if !defined(COIN_EXCLUDE_SOVIEWVOLUMEELEMENT)
#undef COIN_EXCLUDE_SOREPLACEDELEMENT
#endif // !COIN_EXCLUDE_SOVIEWVOLUMEELEMENT
#if !defined(COIN_EXCLUDE_SOREPLACEDELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOREPLACEDELEMENT
#if !defined(COIN_EXCLUDE_SOSHAPEHINTSELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOSHAPEHINTSELEMENT
#if !defined(COIN_EXCLUDE_SOSHAPESTYLEELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOSHAPESTYLEELEMENT
#if !defined(COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOVIEWPORTREGIONELEMENT
#if !defined(COIN_EXCLUDE_SOWINDOWELEMENT)
#undef COIN_EXCLUDE_SOELEMENT
#endif // !COIN_EXCLUDE_SOWINDOWELEMENT


///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Fields' dependency rules                                  //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// Default state for a field is to be disabled, so disable all first. //
////////////////////////////////////////////////////////////////////////

#define COIN_EXCLUDE_SOFIELD 1
#define COIN_EXCLUDE_SOSFIELD 1
#define COIN_EXCLUDE_SOSFBOOL 1
#define COIN_EXCLUDE_SOSFCOLOR 1
#define COIN_EXCLUDE_SOSFENGINE 1
#define COIN_EXCLUDE_SOSFENUM 1
#define COIN_EXCLUDE_SOSFBITMASK 1
#define COIN_EXCLUDE_SOSFFLOAT 1
#define COIN_EXCLUDE_SOSFIMAGE 1
#define COIN_EXCLUDE_SOSFINT32 1
#define COIN_EXCLUDE_SOSFMATRIX 1
#define COIN_EXCLUDE_SOSFNAME 1
#define COIN_EXCLUDE_SOSFNODE 1
#define COIN_EXCLUDE_SOSFPATH 1
#define COIN_EXCLUDE_SOSFPLANE 1
#define COIN_EXCLUDE_SOSFROTATION 1
#define COIN_EXCLUDE_SOSFSHORT 1
#define COIN_EXCLUDE_SOSFSTRING 1
#define COIN_EXCLUDE_SOSFTIME 1
#define COIN_EXCLUDE_SOSFTRIGGER 1
#define COIN_EXCLUDE_SOSFUINT32 1
#define COIN_EXCLUDE_SOSFUSHORT 1
#define COIN_EXCLUDE_SOSFVEC2F 1
#define COIN_EXCLUDE_SOSFVEC3F 1
#define COIN_EXCLUDE_SOSFVEC4F 1
#define COIN_EXCLUDE_SOMFIELD 1
#define COIN_EXCLUDE_SOMFBOOL 1
#define COIN_EXCLUDE_SOMFCOLOR 1
#define COIN_EXCLUDE_SOMFENGINE 1
#define COIN_EXCLUDE_SOMFENUM 1
#define COIN_EXCLUDE_SOMFBITMASK 1
#define COIN_EXCLUDE_SOMFFLOAT 1
#define COIN_EXCLUDE_SOMFINT32 1
#define COIN_EXCLUDE_SOMFMATRIX 1
#define COIN_EXCLUDE_SOMFNAME 1
#define COIN_EXCLUDE_SOMFNODE 1
#define COIN_EXCLUDE_SOMFPATH 1
#define COIN_EXCLUDE_SOMFPLANE 1
#define COIN_EXCLUDE_SOMFROTATION 1
#define COIN_EXCLUDE_SOMFSHORT 1
#define COIN_EXCLUDE_SOMFSTRING 1
#define COIN_EXCLUDE_SOMFTIME 1
#define COIN_EXCLUDE_SOMFUINT32 1
#define COIN_EXCLUDE_SOMFUSHORT 1
#define COIN_EXCLUDE_SOMFVEC2F 1
#define COIN_EXCLUDE_SOMFVEC3F 1
#define COIN_EXCLUDE_SOMFVEC4F 1


////////////////////////////////////////////////////////////
// Node class dependencies on fields.                     //
////////////////////////////////////////////////////////////

//# SoAnnotext3: SoMFString, SoSFFloat, SoSFEnum, SoSFNode, 
#if !defined(COIN_EXCLUDE_SOANNOTEXT3) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFSTRING
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFNODE
#endif // !COIN_EXCLUDE_SOANNOTEXT3  (AUTOGEN)

//# SoAnnotext3property: SoSFEnum, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOANNOTEXT3PROPERTY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOANNOTEXT3PROPERTY  (AUTOGEN)

//# SoAntisquish: SoSFEnum, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOANTISQUISH) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOANTISQUISH  (AUTOGEN)

//# SoArray: SoSFEnum, SoSFShort, SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOARRAY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFSHORT
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOARRAY  (AUTOGEN)

//# SoAsciitext: SoMFString, SoSFFloat, SoSFEnum, SoMFFloat, 
#if !defined(COIN_EXCLUDE_SOASCIITEXT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFSTRING
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOASCIITEXT  (AUTOGEN)

//# SoBasecolor: SoMFColor, 
#if !defined(COIN_EXCLUDE_SOBASECOLOR) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFCOLOR
#endif // !COIN_EXCLUDE_SOBASECOLOR  (AUTOGEN)

//# SoBlinker: SoSFFloat, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOBLINKER) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOBLINKER  (AUTOGEN)

//# SoCamera: SoSFEnum, SoSFVec3f, SoSFRotation, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOCAMERA) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFROTATION
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOCAMERA  (AUTOGEN)

//# SoClipplane: SoSFPlane, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOCLIPPLANE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFPLANE
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOCLIPPLANE  (AUTOGEN)

//# SoColorindex: SoMFInt32, 
#if !defined(COIN_EXCLUDE_SOCOLORINDEX) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOCOLORINDEX  (AUTOGEN)

//# SoComplexity: SoSFEnum, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOCOMPLEXITY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOCOMPLEXITY  (AUTOGEN)

//# SoCone: SoSFBitmask, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOCONE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFBITMASK
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOCONE  (AUTOGEN)

//# SoCoordinate3: SoMFVec3f
#if !defined(COIN_EXCLUDE_SOCOORDINATE3) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#endif // !COIN_EXCLUDE_SOCOORDINATE3  (AUTOGEN)

//# SoCoordinate4: SoMFVec4f
#if !defined(COIN_EXCLUDE_SOCOORDINATE4) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC4F
#endif // !COIN_EXCLUDE_SOCOORDINATE4  (AUTOGEN)

//# SoCube: SoSFFloat
#if !defined(COIN_EXCLUDE_SOCUBE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOCUBE  (AUTOGEN)

//# SoCylinder: SoSFFloat, SoSFBitmask, 
#if !defined(COIN_EXCLUDE_SOCYLINDER) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SOCYLINDER  (AUTOGEN)

//# SoDirectionallight: SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SODIRECTIONALLIGHT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SODIRECTIONALLIGHT  (AUTOGEN)

//# SoDrawstyle: SoSFEnum, SoSFFloat, SoSFUshort, 
#if !defined(COIN_EXCLUDE_SODRAWSTYLE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFUSHORT
#endif // !COIN_EXCLUDE_SODRAWSTYLE  (AUTOGEN)

//# SoEnvironment: SoSFFloat, SoSFColor, SoSFVec3f, SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOENVIRONMENT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFCOLOR
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOENVIRONMENT  (AUTOGEN)

//# SoExtselection: SoSFEnum
#if !defined(COIN_EXCLUDE_SOEXTSELECTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOEXTSELECTION  (AUTOGEN)

//# SoFaceset: SoMFInt32, 
#if !defined(COIN_EXCLUDE_SOFACESET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOFACESET  (AUTOGEN)

//# SoFile: SoSFString, 
#if !defined(COIN_EXCLUDE_SOFILE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFSTRING
#endif // !COIN_EXCLUDE_SOFILE  (AUTOGEN)

//# SoFont: SoSFName, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOFONT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFNAME
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOFONT  (AUTOGEN)

//# SoFontstyle: SoSFEnum, SoSFBitmask, 
#if !defined(COIN_EXCLUDE_SOFONTSTYLE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SOFONTSTYLE  (AUTOGEN)

//# SoImage: SoSFInt32, SoSFEnum, SoSFImage, SoSFString, 
#if !defined(COIN_EXCLUDE_SOIMAGE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFIMAGE
#undef COIN_EXCLUDE_SOSFSTRING
#endif // !COIN_EXCLUDE_SOIMAGE  (AUTOGEN)

//# SoIndexednurbscurve: SoSFInt32, SoMFInt32, SoMFFloat, 
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSCURVE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#undef COIN_EXCLUDE_SOMFINT32
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOINDEXEDNURBSCURVE  (AUTOGEN)

//# SoIndexednurbssurface: SoSFInt32, SoMFInt32, SoMFFloat, 
#if !defined(COIN_EXCLUDE_SOINDEXEDNURBSSURFACE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#undef COIN_EXCLUDE_SOMFINT32
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOINDEXEDNURBSSURFACE  (AUTOGEN)

//# SoIndexedshape: SoMFInt32
#if !defined(COIN_EXCLUDE_SOINDEXEDSHAPE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOINDEXEDSHAPE  (AUTOGEN)

//# SoInfo: SoSFString
#if !defined(COIN_EXCLUDE_SOINFO) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFSTRING
#endif // !COIN_EXCLUDE_SOINFO  (AUTOGEN)

//# SoLOD: SoMFFloat, SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOLOD) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOLOD  (AUTOGEN)

//# SoLabel: SoSFName, 
#if !defined(COIN_EXCLUDE_SOLABEL) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFNAME
#endif // !COIN_EXCLUDE_SOLABEL  (AUTOGEN)

//# SoLevelOfDetail: SoMFFloat, 
#if !defined(COIN_EXCLUDE_SOLEVELOFDETAIL) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOLEVELOFDETAIL  (AUTOGEN)

//# SoLevelofsimplification: SoMFFloat, SoSFInt32, 
#if !defined(COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOLEVELOFSIMPLIFICATION  (AUTOGEN)

//# SoLight: SoSFBool, SoSFFloat, SoSFColor, 
#if !defined(COIN_EXCLUDE_SOLIGHT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFBOOL
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFCOLOR
#endif // !COIN_EXCLUDE_SOLIGHT  (AUTOGEN)

//# SoLightmodel: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOLIGHTMODEL) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOLIGHTMODEL  (AUTOGEN)

//# SoLineset: SoMFInt32, 
#if !defined(COIN_EXCLUDE_SOLINESET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOLINESET  (AUTOGEN)

//# SoLocatehighlight: SoSFColor, SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOLOCATEHIGHLIGHT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFCOLOR
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOLOCATEHIGHLIGHT  (AUTOGEN)

//# SoMarkerset: SoMFInt32
#if !defined(COIN_EXCLUDE_SOMARKERSET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOMARKERSET  (AUTOGEN)

//# SoMaterial: SoMFColor, SoMFFloat, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOMATERIAL) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFCOLOR
#undef COIN_EXCLUDE_SOMFFLOAT
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOMATERIAL  (AUTOGEN)

//# SoMaterialbinding: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOMATERIALBINDING) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOMATERIALBINDING  (AUTOGEN)

//# SoMatrixtransform: SoSFMatrix, 
#if !defined(COIN_EXCLUDE_SOMATRIXTRANSFORM) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFMATRIX
#endif // !COIN_EXCLUDE_SOMATRIXTRANSFORM  (AUTOGEN)

//# SoMultiplecopy: SoMFMatrix, 
#if !defined(COIN_EXCLUDE_SOMULTIPLECOPY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFMATRIX
#endif // !COIN_EXCLUDE_SOMULTIPLECOPY  (AUTOGEN)

//# SoNonindexedshape: SoSFInt32, 
#if !defined(COIN_EXCLUDE_SONONINDEXEDSHAPE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SONONINDEXEDSHAPE  (AUTOGEN)

//# SoNormal: SoMFVec3f, 
#if !defined(COIN_EXCLUDE_SONORMAL) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#endif // !COIN_EXCLUDE_SONORMAL  (AUTOGEN)

//# SoNormalbinding: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SONORMALBINDING) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SONORMALBINDING  (AUTOGEN)

//# SoNurbscurve: SoSFInt32, SoMFFloat, 
#if !defined(COIN_EXCLUDE_SONURBSCURVE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SONURBSCURVE  (AUTOGEN)

//# SoNurbsprofile: SoMFFloat, 
#if !defined(COIN_EXCLUDE_SONURBSPROFILE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SONURBSPROFILE  (AUTOGEN)

//# SoNurbssurface: SoSFInt32, SoMFFloat, 
#if !defined(COIN_EXCLUDE_SONURBSSURFACE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SONURBSSURFACE  (AUTOGEN)

//# SoPackedcolor: SoMFUint32, 
#if !defined(COIN_EXCLUDE_SOPACKEDCOLOR) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFUINT32
#endif // !COIN_EXCLUDE_SOPACKEDCOLOR  (AUTOGEN)

//# SoPathswitch: SoSFPath, 
#if !defined(COIN_EXCLUDE_SOPATHSWITCH) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFPATH
#endif // !COIN_EXCLUDE_SOPATHSWITCH  (AUTOGEN)

//# SoPendulum: SoSFRotation, SoSFFloat, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOPENDULUM) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFROTATION
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOPENDULUM  (AUTOGEN)

//# SoPickstyle: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOPICKSTYLE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOPICKSTYLE  (AUTOGEN)

//# SoPointlight: SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOPOINTLIGHT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOPOINTLIGHT  (AUTOGEN)

//# SoPointset: SoSFInt32, 
#if !defined(COIN_EXCLUDE_SOPOINTSET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOPOINTSET  (AUTOGEN)

//# SoPolygonoffset: SoSFFloat, SoSFBitmask, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOPOLYGONOFFSET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBITMASK
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOPOLYGONOFFSET  (AUTOGEN)

//# SoProfile: SoMFInt32, SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOPROFILE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOPROFILE  (AUTOGEN)

//# SoProfilecoordinate2: SoMFVec2f, 
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE2) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC2F
#endif // !COIN_EXCLUDE_SOPROFILECOORDINATE2  (AUTOGEN)

//# SoProfilecoordinate3: SoMFVec3f, 
#if !defined(COIN_EXCLUDE_SOPROFILECOORDINATE3) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#endif // !COIN_EXCLUDE_SOPROFILECOORDINATE3  (AUTOGEN)

//# SoQuadmesh: SoSFInt32, 
#if !defined(COIN_EXCLUDE_SOQUADMESH) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOQUADMESH  (AUTOGEN)

//# SoResettransform: SoSFBitmask, 
#if !defined(COIN_EXCLUDE_SORESETTRANSFORM) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SORESETTRANSFORM  (AUTOGEN)

//# SoRotation: SoSFRotation, 
#if !defined(COIN_EXCLUDE_SOROTATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFROTATION
#endif // !COIN_EXCLUDE_SOROTATION  (AUTOGEN)

//# SoRotationXYZ: SoSFEnum, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOROTATIONXYZ) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOROTATIONXYZ  (AUTOGEN)

//# SoRotor: SoSFFloat, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOROTOR) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOROTOR  (AUTOGEN)

//# SoScale: SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOSCALE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOSCALE  (AUTOGEN)

//# SoSelection: SoSFEnum
#if !defined(COIN_EXCLUDE_SOSELECTION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOSELECTION  (AUTOGEN)

//# SoSeparator: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOSEPARATOR) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOSEPARATOR  (AUTOGEN)

//# SoShapehints: SoSFEnum, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOSHAPEHINTS) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOSHAPEHINTS  (AUTOGEN)

//# SoShuttle: SoSFVec3f, SoSFFloat, SoSFBool, 
#if !defined(COIN_EXCLUDE_SOSHUTTLE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOSHUTTLE  (AUTOGEN)

//# SoSphere: SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOSPHERE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOSPHERE  (AUTOGEN)

//# SoSpotlight: SoSFVec3f, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOSPOTLIGHT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOSPOTLIGHT  (AUTOGEN)

//# SoSurroundscale: SoSFInt32, 
#if !defined(COIN_EXCLUDE_SOSURROUNDSCALE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOSURROUNDSCALE  (AUTOGEN)

//# SoSwitch: SoSFInt32, 
#if !defined(COIN_EXCLUDE_SOSWITCH) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOSWITCH  (AUTOGEN)

//# SoText2: SoMFString, SoSFFloat, SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOTEXT2) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFSTRING
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOTEXT2  (AUTOGEN)

//# SoText3: SoMFString, SoSFFloat, SoSFEnum, SoSFBitmask, 
#if !defined(COIN_EXCLUDE_SOTEXT3) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFSTRING
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SOTEXT3  (AUTOGEN)

//# SoTexture2: SoSFString, SoSFImage, SoSFEnum, SoSFColor, 
#if !defined(COIN_EXCLUDE_SOTEXTURE2) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFSTRING
#undef COIN_EXCLUDE_SOSFIMAGE
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOSFCOLOR
#endif // !COIN_EXCLUDE_SOTEXTURE2  (AUTOGEN)

//# SoTexture2transform: SoSFVec2f, SoSFFloat, 
#if !defined(COIN_EXCLUDE_SOTEXTURE2TRANSFORM) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC2F
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOTEXTURE2TRANSFORM  (AUTOGEN)

//# SoTexturecoordinate2: SoMFVec2f, 
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATE2) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC2F
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATE2  (AUTOGEN)

//# SoTexturecoordinatebinding: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATEBINDING  (AUTOGEN)

//# SoTexturecoordinateplane: SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOTEXTURECOORDINATEPLANE  (AUTOGEN)

//# SoTransform: SoSFVec3f, SoSFRotation, 
#if !defined(COIN_EXCLUDE_SOTRANSFORM) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFROTATION
#endif // !COIN_EXCLUDE_SOTRANSFORM  (AUTOGEN)

//# SoTranslation: SoSFVec3f, 
#if !defined(COIN_EXCLUDE_SOTRANSLATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOTRANSLATION  (AUTOGEN)

//# SoTrianglestripset: SoMFInt32, 
#if !defined(COIN_EXCLUDE_SOTRIANGLESTRIPSET) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFINT32
#endif // !COIN_EXCLUDE_SOTRIANGLESTRIPSET  (AUTOGEN)

//# SoUnits: SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOUNITS) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOUNITS  (AUTOGEN)

//# SoVertexproperty: SoMFVec3f, SoMFVec2f, SoSFEnum, SoMFUint32, 
#if !defined(COIN_EXCLUDE_SOVERTEXPROPERTY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#undef COIN_EXCLUDE_SOMFVEC2F
#undef COIN_EXCLUDE_SOSFENUM
#undef COIN_EXCLUDE_SOMFUINT32
#endif // !COIN_EXCLUDE_SOVERTEXPROPERTY  (AUTOGEN)

//# SoVertexshape: SoSFNode, 
#if !defined(COIN_EXCLUDE_SOVERTEXSHAPE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFNODE
#endif // !COIN_EXCLUDE_SOVERTEXSHAPE  (AUTOGEN)

//# SoWwwanchor: SoSFString, SoSFEnum, 
#if !defined(COIN_EXCLUDE_SOWWWANCHOR) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFSTRING
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOWWWANCHOR  (AUTOGEN)

//# SoWwwinline: SoSFString, SoSFVec3f, SoSFNode, 
#if !defined(COIN_EXCLUDE_SOWWWINLINE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFSTRING
#undef COIN_EXCLUDE_SOSFVEC3F
#undef COIN_EXCLUDE_SOSFNODE
#endif // !COIN_EXCLUDE_SOWWWINLINE  (AUTOGEN)



////////////////////////////////////////////////////////////
// Engine class dependencies on fields.                   //
////////////////////////////////////////////////////////////

//# SoBoolOperation: SoMFBool, SoMFEnum
#if !defined(COIN_EXCLUDE_SOBOOLOPERATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFBOOL
#undef COIN_EXCLUDE_SOMFENUM
#endif // !COIN_EXCLUDE_SOBOOLOPERATION  (AUTOGEN)

//# SoComposeVec2f: SoMFFloat
#if !defined(COIN_EXCLUDE_SOCOMPOSEVEC2F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOCOMPOSEVEC2F  (AUTOGEN)

//# SoComposeVec3f: SoMFFloat
#if !defined(COIN_EXCLUDE_SOCOMPOSEVEC3F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOCOMPOSEVEC3F  (AUTOGEN)

//# SoComposeVec4f: SoMFFloat
#if !defined(COIN_EXCLUDE_SOCOMPOSEVEC4F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOCOMPOSEVEC4F  (AUTOGEN)

//# SoDecomposeVec2f: SoMFVec2f
#if !defined(COIN_EXCLUDE_SODECOMPOSEVEC2F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC2F
#endif // !COIN_EXCLUDE_SODECOMPOSEVEC2F  (AUTOGEN)

//# SoDecomposeVec3f: SoMFVec3f
#if !defined(COIN_EXCLUDE_SODECOMPOSEVEC3F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#endif // !COIN_EXCLUDE_SODECOMPOSEVEC3F  (AUTOGEN)

//# SoDecomposeVec4f: SoMFVec4f
#if !defined(COIN_EXCLUDE_SODECOMPOSEVEC4F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC4F
#endif // !COIN_EXCLUDE_SODECOMPOSEVEC4F  (AUTOGEN)

//# SoDecomposeRotation: SoMFRotation
#if !defined(COIN_EXCLUDE_SODECOMPOSEROTATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFROTATION
#endif // !COIN_EXCLUDE_SODECOMPOSEROTATION  (AUTOGEN)

//# SoComposeRotation: SoMFVec3f, SoMFFloat
#if !defined(COIN_EXCLUDE_SOCOMPOSEROTATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOCOMPOSEROTATION  (AUTOGEN)

//# SoComposeMatrix: SoMFFloat, SoMFVec3f, SoMFRotation
#if !defined(COIN_EXCLUDE_SOCOMPOSEMATRIX) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#undef COIN_EXCLUDE_SOMFVEC3F
#undef COIN_EXCLUDE_SOMFROTATION
#endif // !COIN_EXCLUDE_SOCOMPOSEMATRIX  (AUTOGEN)

//# SoDecomposeMatrix: SoMFMatrix
#if !defined(COIN_EXCLUDE_SODECOMPOSEMATRIX) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFMATRIX
#endif // !COIN_EXCLUDE_SODECOMPOSEMATRIX  (AUTOGEN)

//# SoConcatenate: SoMField
#if !defined(COIN_EXCLUDE_SOCONCATENATE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOCONCATENATE  (AUTOGEN)

//# SoCounter: SoSFTrigger, SoSFShort
#if !defined(COIN_EXCLUDE_SOCOUNTER) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFTRIGGER
#undef COIN_EXCLUDE_SOSFSHORT
#endif // !COIN_EXCLUDE_SOCOUNTER  (AUTOGEN)

//# SoElapsedTime: SoSFTime, SoSFFloat, SoSFBool, SoSFTrigger
#if !defined(COIN_EXCLUDE_SOELAPSEDTIME) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFTIME
#undef COIN_EXCLUDE_SOSFFLOAT
#undef COIN_EXCLUDE_SOSFBOOL
#undef COIN_EXCLUDE_SOSFTRIGGER
#endif // !COIN_EXCLUDE_SOELAPSEDTIME  (AUTOGEN)

//# SoGate: SoMField, SoSFBool, SoSFTrigger
#if !defined(COIN_EXCLUDE_SOGATE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFIELD
#undef COIN_EXCLUDE_SOSFBOOL
#undef COIN_EXCLUDE_SOSFTRIGGER
#endif // !COIN_EXCLUDE_SOGATE  (AUTOGEN)

//# SoInterpolateFloat: SoMFFloat
#if !defined(COIN_EXCLUDE_SOINTERPOLATEFLOAT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOINTERPOLATEFLOAT  (AUTOGEN)

//# SoInterpolateRotation: SoMFRotation
#if !defined(COIN_EXCLUDE_SOINTERPOLATEROTATION) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFROTATION
#endif // !COIN_EXCLUDE_SOINTERPOLATEROTATION  (AUTOGEN)

//# SoInterpolateVec2f: SoMFVec2f
#if !defined(COIN_EXCLUDE_SOINTERPOLATEVEC2F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC2F
#endif // !COIN_EXCLUDE_SOINTERPOLATEVEC2F  (AUTOGEN)

//# SoInterpolateVec3f: SoMFVec3f
#if !defined(COIN_EXCLUDE_SOINTERPOLATEVEC3F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC3F
#endif // !COIN_EXCLUDE_SOINTERPOLATEVEC3F  (AUTOGEN)

//# SoInterpolateVec4f: SoMFVec4f
#if !defined(COIN_EXCLUDE_SOINTERPOLATEVEC4F) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFVEC4F
#endif // !COIN_EXCLUDE_SOINTERPOLATEVEC4F  (AUTOGEN)

//# SoOnOff: SoSFTrigger
#if !defined(COIN_EXCLUDE_SOONOFF) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFTRIGGER
#endif // !COIN_EXCLUDE_SOONOFF  (AUTOGEN)

//# SoOneShot: SoSFTime, SoSFBool, SoSFTrigger, SoSFBitMask
#if !defined(COIN_EXCLUDE_SOONESHOT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFTIME
#undef COIN_EXCLUDE_SOSFBOOL
#undef COIN_EXCLUDE_SOSFTRIGGER
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SOONESHOT  (AUTOGEN)

//# SoSelectOne: SoMField, SoSFInt32
#if !defined(COIN_EXCLUDE_SOSELECTONE) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFIELD
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOSELECTONE  (AUTOGEN)

//# SoTriggerAny: SoSFTrigger
#if !defined(COIN_EXCLUDE_SOTRIGGERANY) // (AUTOGEN)
#undef COIN_EXCLUDE_SOSFTRIGGER
#endif // !COIN_EXCLUDE_SOTRIGGERANY  (AUTOGEN)



////////////////////////////////////////////////////////////
// Miscellaneous dependencies on fields.                  //
////////////////////////////////////////////////////////////

// SoDB uses an SoSFTime for the realTime global field. I don't think
// there's much we can do about this.. --mortene
#undef COIN_EXCLUDE_SOSFTIME

//# SoLazyElement: SoMFColor, SoMFFloat
#if !defined(COIN_EXCLUDE_SOLAZYELEMENT) // (AUTOGEN)
#undef COIN_EXCLUDE_SOMFCOLOR
#undef COIN_EXCLUDE_SOMFFLOAT
#endif // !COIN_EXCLUDE_SOLAZYELEMENT  (AUTOGEN)


//////////////////////////////////////////////////////////////////////
// Subclass->superclass and multifield->singlefield dependencies    //
// among fields.                                                    //
//////////////////////////////////////////////////////////////////////

// multifield->singlefield

#if !defined(COIN_EXCLUDE_SOMFBOOL)
#undef COIN_EXCLUDE_SOSFBOOL
#endif // !COIN_EXCLUDE_SOMFBOOL
#if !defined(COIN_EXCLUDE_SOMFBITMASK)
#undef COIN_EXCLUDE_SOSFBITMASK
#endif // !COIN_EXCLUDE_SOMFBITMASK
#if !defined(COIN_EXCLUDE_SOMFCOLOR)
#undef COIN_EXCLUDE_SOSFCOLOR
#endif // !COIN_EXCLUDE_SOMFCOLOR
#if !defined(COIN_EXCLUDE_SOMFENGINE)
#undef COIN_EXCLUDE_SOSFENGINE
#endif // !COIN_EXCLUDE_SOMFENGINE
#if !defined(COIN_EXCLUDE_SOMFENUM)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOMFENUM
#if !defined(COIN_EXCLUDE_SOMFFLOAT)
#undef COIN_EXCLUDE_SOSFFLOAT
#endif // !COIN_EXCLUDE_SOMFFLOAT
#if !defined(COIN_EXCLUDE_SOMFINT32)
#undef COIN_EXCLUDE_SOSFINT32
#endif // !COIN_EXCLUDE_SOMFINT32
#if !defined(COIN_EXCLUDE_SOMFMATRIX)
#undef COIN_EXCLUDE_SOSFMATRIX
#endif // !COIN_EXCLUDE_SOMFMATRIX
#if !defined(COIN_EXCLUDE_SOMFNAME)
#undef COIN_EXCLUDE_SOSFNAME
#endif // !COIN_EXCLUDE_SOMFNAME
#if !defined(COIN_EXCLUDE_SOMFNODE)
#undef COIN_EXCLUDE_SOSFNODE
#endif // !COIN_EXCLUDE_SOMFNODE
#if !defined(COIN_EXCLUDE_SOMFPATH)
#undef COIN_EXCLUDE_SOSFPATH
#endif // !COIN_EXCLUDE_SOMFPATH
#if !defined(COIN_EXCLUDE_SOMFPLANE)
#undef COIN_EXCLUDE_SOSFPLANE
#endif // !COIN_EXCLUDE_SOMFPLANE
#if !defined(COIN_EXCLUDE_SOMFROTATION)
#undef COIN_EXCLUDE_SOSFROTATION
#endif // !COIN_EXCLUDE_SOMFROTATION
#if !defined(COIN_EXCLUDE_SOMFSHORT)
#undef COIN_EXCLUDE_SOSFSHORT
#endif // !COIN_EXCLUDE_SOMFSHORT
#if !defined(COIN_EXCLUDE_SOMFSTRING)
#undef COIN_EXCLUDE_SOSFSTRING
#endif // !COIN_EXCLUDE_SOMFSTRING
#if !defined(COIN_EXCLUDE_SOMFTIME)
#undef COIN_EXCLUDE_SOSFTIME
#endif // !COIN_EXCLUDE_SOMFTIME
#if !defined(COIN_EXCLUDE_SOMFUINT32)
#undef COIN_EXCLUDE_SOSFUINT32
#endif // !COIN_EXCLUDE_SOMFUINT32
#if !defined(COIN_EXCLUDE_SOMFUSHORT)
#undef COIN_EXCLUDE_SOSFUSHORT
#endif // !COIN_EXCLUDE_SOMFUSHORT
#if !defined(COIN_EXCLUDE_SOMFVEC2F)
#undef COIN_EXCLUDE_SOSFVEC2F
#endif // !COIN_EXCLUDE_SOMFVEC2F
#if !defined(COIN_EXCLUDE_SOMFVEC3F)
#undef COIN_EXCLUDE_SOSFVEC3F
#endif // !COIN_EXCLUDE_SOMFVEC3F
#if !defined(COIN_EXCLUDE_SOMFVEC4F)
#undef COIN_EXCLUDE_SOSFVEC4F
#endif // !COIN_EXCLUDE_SOMFVEC4F


// subclass->superclass

#if !defined(COIN_EXCLUDE_SOSFBOOL)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFBOOL
#if !defined(COIN_EXCLUDE_SOSFCOLOR)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFCOLOR
#if !defined(COIN_EXCLUDE_SOSFENGINE)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFENGINE
#if !defined(COIN_EXCLUDE_SOSFBITMASK)
#undef COIN_EXCLUDE_SOSFENUM
#endif // !COIN_EXCLUDE_SOSFBITMASK
#if !defined(COIN_EXCLUDE_SOSFENUM)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFENUM
#if !defined(COIN_EXCLUDE_SOSFENUM)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFENUM
#if !defined(COIN_EXCLUDE_SOSFFLOAT)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFFLOAT
#if !defined(COIN_EXCLUDE_SOSFIMAGE)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFIMAGE
#if !defined(COIN_EXCLUDE_SOSFINT32)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFINT32
#if !defined(COIN_EXCLUDE_SOSFMATRIX)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFMATRIX
#if !defined(COIN_EXCLUDE_SOSFNAME)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFNAME
#if !defined(COIN_EXCLUDE_SOSFNODE)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFNODE
#if !defined(COIN_EXCLUDE_SOSFPATH)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFPATH
#if !defined(COIN_EXCLUDE_SOSFPLANE)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFPLANE
#if !defined(COIN_EXCLUDE_SOSFROTATION)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFROTATION
#if !defined(COIN_EXCLUDE_SOSFSHORT)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFSHORT
#if !defined(COIN_EXCLUDE_SOSFSTRING)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFSTRING
#if !defined(COIN_EXCLUDE_SOSFTIME)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFTIME
#if !defined(COIN_EXCLUDE_SOSFTRIGGER)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFTRIGGER
#if !defined(COIN_EXCLUDE_SOSFUINT32)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFUINT32
#if !defined(COIN_EXCLUDE_SOSFUSHORT)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFUSHORT
#if !defined(COIN_EXCLUDE_SOSFVEC2F)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFVEC2F
#if !defined(COIN_EXCLUDE_SOSFVEC3F)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFVEC3F
#if !defined(COIN_EXCLUDE_SOSFVEC4F)
#undef COIN_EXCLUDE_SOSFIELD
#endif // !COIN_EXCLUDE_SOSFVEC4F
#if !defined(COIN_EXCLUDE_SOSFIELD)
#undef COIN_EXCLUDE_SOFIELD
#endif // !COIN_EXCLUDE_SOSFIELD
#if !defined(COIN_EXCLUDE_SOMFBOOL)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFBOOL
#if !defined(COIN_EXCLUDE_SOMFCOLOR)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFCOLOR
#if !defined(COIN_EXCLUDE_SOMFENGINE)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFENGINE
#if !defined(COIN_EXCLUDE_SOMFBITMASK)
#undef COIN_EXCLUDE_SOMFENUM
#endif // !COIN_EXCLUDE_SOMFBITMASK
#if !defined(COIN_EXCLUDE_SOMFENUM)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFENUM
#if !defined(COIN_EXCLUDE_SOMFFLOAT)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFFLOAT
#if !defined(COIN_EXCLUDE_SOMFINT32)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFINT32
#if !defined(COIN_EXCLUDE_SOMFMATRIX)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFMATRIX
#if !defined(COIN_EXCLUDE_SOMFNAME)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFNAME
#if !defined(COIN_EXCLUDE_SOMFNODE)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFNODE
#if !defined(COIN_EXCLUDE_SOMFPATH)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFPATH
#if !defined(COIN_EXCLUDE_SOMFPLANE)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFPLANE
#if !defined(COIN_EXCLUDE_SOMFROTATION)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFROTATION
#if !defined(COIN_EXCLUDE_SOMFSHORT)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFSHORT
#if !defined(COIN_EXCLUDE_SOMFSTRING)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFSTRING
#if !defined(COIN_EXCLUDE_SOMFTIME)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFTIME
#if !defined(COIN_EXCLUDE_SOMFUINT32)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFUINT32
#if !defined(COIN_EXCLUDE_SOMFUSHORT)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFUSHORT
#if !defined(COIN_EXCLUDE_SOMFVEC2F)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFVEC2F
#if !defined(COIN_EXCLUDE_SOMFVEC3F)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFVEC3F
#if !defined(COIN_EXCLUDE_SOMFVEC4F)
#undef COIN_EXCLUDE_SOMFIELD
#endif // !COIN_EXCLUDE_SOMFVEC4F
#if !defined(COIN_EXCLUDE_SOMFIELD)
#undef COIN_EXCLUDE_SOFIELD
#endif // !COIN_EXCLUDE_SOMFIELD

///////////////////////////////////////////////////////////////////////////
//                                                                       //
//             Miscellaneous dependency rules                            //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

//# !SoAction: !SoState
#if defined(COIN_EXCLUDE_SOACTION) // (AUTOGEN)
#define COIN_EXCLUDE_SOSTATE 1
#endif // COIN_EXCLUDE_SOACTION  (AUTOGEN)

//# !SoGroup: !SoPath
#if defined(COIN_EXCLUDE_SOGROUP) // (AUTOGEN)
#define COIN_EXCLUDE_SOPATH 1
#endif // COIN_EXCLUDE_SOGROUP  (AUTOGEN)

//# !SoPath: !SoFullPath
#if defined(COIN_EXCLUDE_SOPATH) // (AUTOGEN)
#define COIN_EXCLUDE_SOFULLPATH 1
#endif // COIN_EXCLUDE_SOPATH  (AUTOGEN)

//# !SoCoordinateElement: !SoConvexDataCache
#if defined(COIN_EXCLUDE_SOCOORDINATEELEMENT) // (AUTOGEN)
#define COIN_EXCLUDE_SOCONVEXDATACACHE 1
#endif // COIN_EXCLUDE_SOCOORDINATEELEMENT  (AUTOGEN)


// ** EOF ******************************************************************

#endif // !COIN_EXCLUDE_NOTHING

#endif // !__CONFDEP_H__
