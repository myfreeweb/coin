/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2004 by Systems in Motion.  All rights reserved.
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
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

// This file contains various functions that are shared between two or
// more field classes.
//
// Typically there's some common code for both the single-field value
// and multiple-field value version of the same field-type.

// *************************************************************************

// FIXME: SoSFEnum and SoMFEnum could probably share some of their
// read / write code. Ditto for SoSFImage and SoSFImage3. If so, it
// should be collected here. 20040630 mortene.

// *************************************************************************

#include <Inventor/C/tidbitsp.h>
#include <Inventor/SbMatrix.h>
#include <Inventor/SbName.h>
#include <Inventor/SbPlane.h>
#include <Inventor/SbRotation.h>
#include <Inventor/SbTime.h>
#include <Inventor/SbVec2f.h>
#include <Inventor/SbVec3d.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbVec4f.h>
#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/errors/SoReadError.h>
#include <Inventor/fields/SoField.h>
#include <Inventor/nodes/SoNode.h>

// *************************************************************************

// Read boolean value from input stream, return TRUE if
// successful. Used from SoSFBool and SoMFBool.
SbBool
sosfbool_read_value(SoInput * in, SbBool & val)
{
  // accept 0 or 1
  if (in->read(val)) {
    if (val != 0 && val != 1) {
      SoReadError::post(in, "Illegal value for field: %d (must be 0 or 1)",
                        val);
      return FALSE;
    }
    return TRUE;
  }

  if (in->isBinary()) {
    SoReadError::post(in, "Premature end of file");
    return FALSE;
  }

  // read TRUE/FALSE keyword

  SbName n;
  if (!in->read(n, TRUE)) {
    SoReadError::post(in, "Couldn't read field value");
    return FALSE;
  }

  if (n == "TRUE") {
    val = TRUE;
    return TRUE;
  }

  if (n == "FALSE") {
    val = FALSE;
    return TRUE;
  }

  SoReadError::post(in,
                    "Invalid value \"%s\" for field (must be TRUE or FALSE)",
                    n.getString());
  return FALSE;
}


// Write boolean value to output stream. Used from SoSFBool and
// SoMFBool.
void
sosfbool_write_value(SoOutput * out, SbBool val)
{
  if (out->isBinary()) out->write((unsigned int)(val ? 1 : 0));
  else out->write(val ? "TRUE" : "FALSE");
}

// *************************************************************************

// Write floating point value to output stream. Used from SoSFFloat
// and SoMFFloat.
void
sosffloat_write_value(SoOutput * out, float val)
{
  out->write(val);
}

// *************************************************************************

// Write SbString value to output stream. Used from SoSFString and
// SoMFString.
void
sosfstring_write_value(const SoField * f, SoOutput * out, const SbString & val)
{
  // VRML97 needs backslashes themselves to be backslash-quoted (like
  // in e.g. C strings), which is taken care of here instead of
  // downstream, as this is the last place we can find out whether or
  // not we're writing a VRML97 node.
  const SoFieldContainer * fc = f->getContainer();
  if (fc && fc->isOfType(SoNode::getClassTypeId()) &&
      (((SoNode *)fc)->getNodeType() & SoNode::VRML2)) {
    // FIXME: SbString should have had a replaceAll() method, so we
    // wouldn't have to spell out the iteration loop below. 20040614 mortene.
    SbString ws;
    for (int i = 0; i < val.getLength(); i++) {
      if (val[i] == '\\') { ws += '\\'; }
      ws += val[i];
    }
    out->write(ws);
  }
  else { // *Not* a VRML97 node, so write backslashes verbatim, as
         // dictated by the Inventor file format:
    out->write(val);
  }
}

// *************************************************************************

// Write matrix to output stream. Used from SoSFMatrix and SoMFMatrix.
void
sosfmatrix_write_value(SoOutput * out, const SbMatrix & m)
{
  if (out->isBinary()) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        out->write(m[i][j]);
      }
    }
    return;
  }


  for(int k=0; k < 4; k++) {
    out->write(m[0][k]);
    if(k != 3) out->write(' ');
  }

  out->write('\n');
  out->incrementIndent();

  for(int i=1; i < 4; i++) {
    out->indent();
    for(int j=0; j < 4; j++) {
      out->write(m[i][j]);
      if(j != 3) out->write(' ');
    }
    if(i != 3) out->write('\n');
  }

  out->decrementIndent();
}

// *************************************************************************

// Read SbPlane from input stream, return TRUE if successful.  Used
// from SoSFPlane and SoMFPlane.
SbBool
sosfplane_read_value(SoInput * in, SbPlane & p)
{
  float f[4];
  for (int i = 0; i < 4; i++) {
    if (!in->read(f[i])) return FALSE;
  }
  p = SbPlane(SbVec3f(f[0], f[1], f[2]), f[3]);
  return TRUE;
}

// Write SbPlane value to output stream. Used from SoSFPlane and
// SoMFPlane.
void
sosfplane_write_value(SoOutput * out, const SbPlane & p)
{
  out->write(p.getNormal()[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(p.getNormal()[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(p.getNormal()[2]);
  if (!out->isBinary()) out->write("  ");
  out->write(p.getDistanceFromOrigin());
}

// *************************************************************************

// Read rotation value from input stream, return TRUE if
// successful. Used from SoSFRotation and SoMFRotation.
SbBool
sosfrotation_read_value(SoInput * in, SbRotation & r)
{
  float f[4];
  for (int i = 0; i < 4; i++) {
    if (!in->read(f[i])) return FALSE;
  }
  SbVec3f axis(f[0], f[1], f[2]);
  const float angle = f[3];

  // vrml97 identity rotations are often specified with a null vector.
  // test for this and just set to z-axis.
  if (axis == SbVec3f(0.0f, 0.0f, 0.0f) && angle == 0.0f) {
    axis = SbVec3f(0.0f, 0.0f, 1.0f);
  }
  r.setValue(axis, angle);
  return TRUE;
}

// Write SbRotation to output stream. Used from SoSFRotation and
// SoMFRotation.
void
sosfrotation_write_value(SoOutput * out, const SbRotation & r)
{
  SbVec3f axis;
  float angle;
  r.getValue(axis, angle);

  // Handle invalid rotation specifications.
  if (axis.length() == 0.0f) {
    axis.setValue(0.0f, 0.0f, 1.0f);
    angle = 0.0f;
  }

  out->write(axis[0]);
  if(!out->isBinary()) out->write(' ');
  out->write(axis[1]);
  if(!out->isBinary()) out->write(' ');
  out->write(axis[2]);
  if(!out->isBinary()) out->write("  ");
  out->write(angle);
}

// *************************************************************************

// Write integer value to output stream. Used from SoSFShort and
// SoMFShort.
void
sosfshort_write_value(SoOutput * out, short val)
{
  out->write(val);
}

// *************************************************************************

// Read SbTime from input stream, return TRUE if successful. Used from
// SoSFTime and SoMFTime.
SbBool
sosftime_read_value(SoInput * in, SbTime & t)
{
  double val;
  if (!in->read(val)) {
    SoReadError::post(in, "unable to read floating point value");
    return FALSE;
  }

  if (!coin_finite(val)) {
    SoReadError::post(in,
                      "Detected non-valid floating point number, replacing "
                      "with 0.0f");
    val = 0.0;
    // We don't return FALSE, thereby allowing the read process to
    // continue, as a convenience for the application programmer.
  }

  t.setValue(val);
  return TRUE;
}

// Write SbTime value to output stream. Used from SoSFTime and
// SoMFTime.
void
sosftime_write_value(SoOutput * out, const SbTime & p)
{
  out->write(p.getValue());
}

// *************************************************************************

// Write integer value to output stream. Used from SoSFUInt32 and
// SoMFUInt32.
void
sosfuint32_write_value(SoOutput * out, uint32_t val)
{
  unsigned int tmp = (unsigned int) val;
  out->write(tmp);
}

// *************************************************************************

// Write integer value to output stream. Used from SoSFUShort and
// SoMFUShort.
void
sosfushort_write_value(SoOutput * out, unsigned short val)
{
  out->write(val);
}

// *************************************************************************

// Write to output stream. Used from SoSFVec2f and SoMFVec2f.
void
sosfvec2f_write_value(SoOutput * out, const SbVec2f & v)
{
  out->write(v[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[1]);
}

// *************************************************************************


// Read from input stream, return TRUE if successful. Used from
// SoSFVec3d and SoMFVec3f.
SbBool
sosfvec3d_read_value(SoInput * in, SbVec3d & v)
{
  if (!in->read(v[0]) || !in->read(v[1]) || !in->read(v[2])) {
    SoReadError::post(in, "Couldn't read vector");
    return FALSE;
  }
  return TRUE;
}

// Write to output stream. Used from SoSFVec3d and SoMFVec3d.
void
sosfvec3d_write_value(SoOutput * out, const SbVec3d & v)
{
  out->write(v[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[2]);
}

// *************************************************************************

// Write to output stream. Used from SoSFVec3f, SoMFVec3f, and
// SoSFColor.
void
sosfvec3f_write_value(SoOutput * out, const SbVec3f & v)
{
  out->write(v[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[2]);
}

// *************************************************************************


// Write to output stream. Used from SoSFVec4f and SoMFVec4f.
void
sosfvec4f_write_value(SoOutput * out, const SbVec4f & v)
{
  out->write(v[0]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[1]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[2]);
  if (!out->isBinary()) out->write(' ');
  out->write(v[3]);
}

// *************************************************************************