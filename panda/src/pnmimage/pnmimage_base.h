// Filename: pnmimage_base.h
// Created by:  drose (14Jun00)
// 
////////////////////////////////////////////////////////////////////

#ifndef PNMIMAGE_BASE_H
#define PNMIMAGE_BASE_H

// This header file make a few typedefs and other definitions
// essential to everything in the PNMImage package.

#include <pandabase.h>

#include <stdio.h>
#include <string>

// These include files are kludges against slightly incorrect headers given
// in pbm*.h.
#include <stdlib.h>
#include <math.h>
#include <algorithm>

extern "C" {
  #include <pbmplus.h>
  #include <pbm.h>
  #include <pgm.h>
  #include <ppm.h>
  #include <pnm.h>
}


// Got to undefine the stupid macros that pbmplus leaves us with.
#ifdef index
  #undef index
  #undef rindex
#endif

// These ratios are used to compute the brightness of a colored pixel; they
// define the relative contributions of each of the components.
static const double lumin_red = 0.299;
static const double lumin_grn = 0.587;
static const double lumin_blu = 0.114;

// A handy template function.
template <class Type>
INLINE Type
bounds(const Type &value, const Type &lower, const Type &upper) {
  return min(max(value, lower), upper);
}


#endif
