/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2003 by Systems in Motion.  All rights reserved.
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
 *  See <URL:http://www.coin3d.org> for  more information.
 *
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no>.
 *
\**************************************************************************/

/*!
  \class SoGlyph include/Inventor/misc/SoGlyph.h
  \brief The SoGlyph class is used to control and reuse font glyphs.

*/

#include <Inventor/misc/SoGlyph.h>

#include <Inventor/C/threads/threadsutilp.h>
#include <Inventor/C/tidbits.h>
#include <Inventor/C/tidbitsp.h>
#include <Inventor/SbName.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/lists/SbList.h>
#include <stdlib.h>
#include <string.h>

#if !defined(COIN_NO_DEFAULT_3DFONT)
// our default font (misc/default3dfont.cpp)
extern float * coin_defaultfont_coords[];
extern int * coin_defaultfont_faceidx[];
extern int * coin_defaultfont_edgeidx[];
#endif // COIN_NO_DEFAULT_3DFONT

#undef THIS
#define THIS this->pimpl

class SoGlyphP {
public:
  SbVec2f * coords;
  SbBox2f bbox;
  int * faceidx;
  int * edgeidx;
  int refcount;
  float ymin, ymax;

  struct {
    unsigned int didalloccoords : 1;
    unsigned int didallocfaceidx : 1;
    unsigned int didallocedgeidx : 1;
    unsigned int didcalcbbox : 1;
  } flags;

  static SoGlyph *createSystemGlyph(const char character, const SbName & font);
  static SoGlyph *createSystemGlyph(const unsigned int character, SoState * state) {return NULL;};
};


/*!
  Constructor.
*/
SoGlyph::SoGlyph()
{
  THIS = new SoGlyphP();
  THIS->refcount = 0;
  THIS->flags.didalloccoords = 0;
  THIS->flags.didallocfaceidx  = 0;
  THIS->flags.didallocedgeidx = 0;
  THIS->flags.didcalcbbox = 0;
  THIS->coords = NULL;
  THIS->faceidx = NULL;
  THIS->edgeidx = NULL;
  THIS->ymin = 0.0f;
  THIS->ymax = 0.0f;
}

/*!
  Destructor.
*/
SoGlyph::~SoGlyph()
{
  if (THIS->flags.didalloccoords) delete [] THIS->coords;
  if (THIS->flags.didallocfaceidx) delete [] THIS->faceidx;
  if (THIS->flags.didallocedgeidx) delete [] THIS->edgeidx;
  delete THIS;
}

/*!
  Should be called when a node no longer will use a glyph. Will
  free memory used by this glyph when it is no longer used by any node.
*/
void
SoGlyph::unref() const
{
  SoGlyph::unrefGlyph((SoGlyph*)this);
}

/*!
  Returns coordinates for this glyph.
*/
const SbVec2f *
SoGlyph::getCoords(void) const
{
  return THIS->coords;
}

/*!
  Returns face indices for this glyph.
*/
const int *
SoGlyph::getFaceIndices(void) const
{
  return THIS->faceidx;
}

/*!
  Returns edge indices for this glyph.
*/
const int *
SoGlyph::getEdgeIndices(void) const
{
  return THIS->edgeidx;
}

/*!
  Returns a pointer to the next clockwise edge. Returns NULL if
  none could be found.
*/
const int * 
SoGlyph::getNextCWEdge(const int edgeidx) const
{
  int idx = edgeidx * 2;
  // test for common case
  if (edgeidx > 0) {
    if (THIS->edgeidx[idx] == THIS->edgeidx[idx-1])
      return &THIS->edgeidx[idx-2];
  }
  // do a linear search
  int findidx = THIS->edgeidx[idx];
  int * ptr = THIS->edgeidx;
  while (*ptr >= 0) {
    if (ptr[1] == findidx) return ptr;
    ptr += 2;
  }
  return NULL;
}

/*!
  Returns a pointer to the next counter clockwise edge. 
  NULL if none could be found.
*/
const int * 
SoGlyph::getNextCCWEdge(const int edgeidx) const
{
  int idx = edgeidx * 2;
  // test for common case
  if (THIS->edgeidx[idx+1] == THIS->edgeidx[idx+2])
    return &THIS->edgeidx[idx+2];
  // do a linear search
  int findidx = THIS->edgeidx[idx+1];
  int * ptr = THIS->edgeidx;
  while (*ptr >= 0) {
    if (*ptr == findidx) return ptr;
    ptr += 2;
  }
  return NULL;
}

/*!
  Convenience method which returns the exact width of the glyph.
*/
float
SoGlyph::getWidth(void) const
{
  const SbBox2f & box = this->getBoundingBox();
  return box.getMax()[0] - box.getMin()[0];
}

/*!
  Returns the bounding box of this glyph. This value is cached for performance.
*/
const SbBox2f &
SoGlyph::getBoundingBox(void) const
{
  // this method needs to be const, so cast away constness
  SoGlyph * thisp = (SoGlyph*) this;
  if (!THIS->flags.didcalcbbox) {
    thisp->pimpl->bbox.makeEmpty();
    int *ptr = THIS->edgeidx;
    int idx = *ptr++;
    while (idx >= 0) {
      thisp->pimpl->bbox.extendBy(THIS->coords[idx]);
      idx = *ptr++;
    }
    thisp->pimpl->flags.didcalcbbox = 1;
  }
  return THIS->bbox;
}

/*!
  Sets the coordinates for this glyph. If \a numcoords > 0, the data
  will be copied before returing. If \a numcoords <= 0, \a coords will
  be used directly.
*/
void
SoGlyph::setCoords(SbVec2f *coords, int numcoords)
{
  if (THIS->flags.didalloccoords) delete [] THIS->coords;
  if (numcoords > 0) {
    THIS->coords = new SbVec2f[numcoords];
    memcpy(THIS->coords, coords, numcoords*sizeof(SbVec2f));
    THIS->flags.didalloccoords = 1;
  }
  else {
    THIS->coords = coords;
    THIS->flags.didalloccoords = 0;
  }
}

/*!
  Sets the face indices for this glyph. If \a numindices > 0, the
  data will be copied before returning. If \a numcoords <= 0,
  \a indices will be used directly.
*/
void
SoGlyph::setFaceIndices(int *indices, int numindices)
{
  if (THIS->flags.didallocfaceidx) delete [] THIS->faceidx;
  if (numindices > 0) {
    THIS->faceidx = new int[numindices];
    memcpy(THIS->faceidx, indices, numindices*sizeof(int));
    THIS->flags.didallocfaceidx = 1;
  }
  else {
    THIS->faceidx = indices;
    THIS->flags.didallocfaceidx = 0;
  }
}

/*!
  Sets the edge indices for this glyph. If \a numindices > 0, the
  data will be copied before returning. If \a numcoords <= 0,
  \a indices will be used directly.
*/
void
SoGlyph::setEdgeIndices(int *indices, int numindices)
{
  if (THIS->flags.didallocedgeidx) delete [] THIS->edgeidx;
  if (numindices > 0) {
    THIS->edgeidx = new int[numindices];
    memcpy(THIS->edgeidx, indices, numindices*sizeof(int));
    THIS->flags.didallocedgeidx = 1;
  }
  else {
    THIS->edgeidx = indices;
    THIS->flags.didallocedgeidx = 0;
  }
}



//
// static methods to handle glyph reusage.
//
// FIXME: use SbDict to look up glyphs a bit faster. pederb, 20000323
//

class coin_glyph_info {
public:
  coin_glyph_info() {
    this->character = 0;
    this->glyph = NULL;
  }
  coin_glyph_info(const char character, const SbName &font, SoGlyph *glyph)
    : character(character), font(font), glyph(glyph) {}

  SbBool matches(const char character, const SbName font) {
    return (this->character == character) && (this->font == font);
  }

  // AIX native compiler xlC needs equality and inequality operators
  // to compile templates where these operators are referenced (even
  // if they are actually never used).

  SbBool operator==(const coin_glyph_info & gi) {
    return this->matches(gi.character, gi.font) && this->glyph == gi.glyph;
  }
  SbBool operator!=(const coin_glyph_info & gi) {
    return !(*this == gi);
  }

  char character;
  SbName font;
  SoGlyph *glyph;
};

static SbList <coin_glyph_info> *activeGlyphs = NULL;
static void * SoGlyph_mutex = NULL;

void SoGlyph_cleanup(void)
{
  delete activeGlyphs;
  CC_MUTEX_DESTRUCT(SoGlyph_mutex);
}

/*!
  Returns a character of the specified font.
*/
const SoGlyph *
SoGlyph::getGlyph(const char character, const SbName &font)
{
  if (SoGlyph_mutex == NULL) {
    CC_MUTEX_CONSTRUCT(SoGlyph_mutex);
  }

  // FIXME: it would probably be a good idea to have a small LRU-type
  // glyph cache to avoid freeing glyphs too early. If for instance the user
  // creates a single SoText3 node which is used several times in a
  // graph with differnet fonts, glyphs will be freed and recreated
  // all the time. pederb, 20000324

  CC_MUTEX_LOCK(SoGlyph_mutex);

  if (activeGlyphs == NULL) {
    activeGlyphs = new SbList <coin_glyph_info>;
    coin_atexit((coin_atexit_f *)SoGlyph_cleanup, 0);
  }

  int i, n = activeGlyphs->getLength();
  for (i = 0; i < n; i++) {
    if ((*activeGlyphs)[i].matches(character, font)) break;
  }
  if (i < n) {
    SoGlyph *glyph = (*activeGlyphs)[i].glyph;
    glyph->pimpl->refcount++;
    CC_MUTEX_UNLOCK(SoGlyph_mutex);
    return glyph;
  }
  
  SoGlyph *glyph = SoGlyphP::createSystemGlyph(character, font);
  if (glyph == NULL) { // no system font could be loaded
#if defined(COIN_NO_DEFAULT_3DFONT)
    // just create a square to render something
    glyph = new SoGlyph;
    static float dummycoords[] = {0.0f, 0.0f, 0.7f, 0.0f, 0.7f, 0.7f, 0.0f, 0.7f};
    static int dummyfaceidx[] = {0,1,2,0,2,3,-1};
    static int dummyedgeidx[] = {0,1,1,2,2,3,3,0,-1};
    glyph->setCoords((SbVec2f*)dummycoords);
    glyph->setFaceIndices(dummyfaceidx);
    glyph->setEdgeIndices(dummyedgeidx);
#else // ! COIN_NO_DEFAULT_3DFONT
    glyph = new SoGlyph;
    if (character <= 32 || character >= 127) {
      // treat all these characters as spaces
      static int spaceidx[] = { -1 };
      glyph->setCoords(NULL);
      glyph->setFaceIndices(spaceidx);
      glyph->setEdgeIndices(spaceidx);
      glyph->pimpl->bbox.setBounds(SbVec2f(0.0f, 0.0f), SbVec2f(0.2f, 0.0f));
      glyph->pimpl->flags.didcalcbbox = 1;
    }
    else {
      glyph->setCoords((SbVec2f*)coin_defaultfont_coords[character-33]);
      glyph->setFaceIndices(coin_defaultfont_faceidx[character-33]);
      glyph->setEdgeIndices(coin_defaultfont_edgeidx[character-33]);
    }
#endif // COIN_NO_DEFAULT_3DFONT
  }
  coin_glyph_info info(character, font, glyph);
  glyph->pimpl->refcount++;
  activeGlyphs->append(info);
  CC_MUTEX_UNLOCK(SoGlyph_mutex);
  return glyph;
}

// private method that removed glyph from active list when deleted
void
SoGlyph::unrefGlyph(SoGlyph *glyph)
{
  CC_MUTEX_LOCK(SoGlyph_mutex);
  assert(activeGlyphs);
  assert(glyph->pimpl->refcount > 0);
  glyph->pimpl->refcount--;
  if (glyph->pimpl->refcount == 0) {
    int i, n = activeGlyphs->getLength();
    for (i = 0; i < n; i++) {
      if ((*activeGlyphs)[i].glyph == glyph) break;
    }
    assert(i < n);
    activeGlyphs->removeFast(i);
    delete glyph;
  }
  CC_MUTEX_UNLOCK(SoGlyph_mutex);
}

// Get glyph according to state's font elements.
// The size parameter overrides state's FontSizeElement (if not SbVec2s(0,0))
const SoGlyph *
getGlyph(SoState * state,
         const unsigned int character, 
         const SbVec2s & size,
         const float angle)
{
  return NULL;
}

// Pixel advance for this glyph.
SbVec2s 
getAdvance()
{
  return SbVec2s(0,0);
}

// Pixel kerning when rightglyph is placed to the right of this.
SbVec2s 
getKerning(const SoGlyph &rightglyph)
{
  return SbVec2s(0,0);
}

// Bitmap for glyph. size and pos are return parameters.
// antialiased -> 8 bits per pixel
// !antialiased -> 1 bit per pixel.
// Only 1bbp currently supported.
unsigned char * 
getBitmap(SbVec2s &size, SbVec2s &pos, const SbBool antialiased)
{
  return NULL;
}

// should handle platform-specific font loading
SoGlyph *
SoGlyphP::createSystemGlyph(const char character, const SbName &font)
{
  // FIXME: implement me somebody, please
  return NULL;
}



