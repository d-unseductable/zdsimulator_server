#ifndef __TYPES_H__
#define __TYPES_H__

typedef unsigned char   uchar;
typedef unsigned short  ushort;

struct TPoint4
{
  float itsX;
  float itsY;
  float itsZ;
  float itsAngle;
};

struct TrSp
{
  ushort  itsTrack;
  float   itsSpeed;
};

#endif
