#ifndef __NETSTRUCT_H__
#define __NETSTRUCT_H__

#include "Types.h"

struct TNConnect
{
  ushort  itsTrainNum;
  uchar   itsDirection;
  ushort  itsSigNum;
  ushort  itsTrackId;
  ushort  itsLocoType;
  uchar   itsCarNum;
};

struct TNConnectAns
{
  uchar Req;
  uchar Code;
};

struct TNCoords
{
  ushort  itsTrainNum;
  ushort  itsHeadTrackId;
  ushort  itsTailTrackId;
  float   itsSpeed;
};

struct TNSvetofor
{
  ushort  itsId;
  uchar   itsValue;
};

struct TVisibles
{
  TTrain  *itsTrain[2];
};

struct TNTraf
{
  ushort  itsTrainNum;
  ushort  itsLocoType;
  ushort  itsHeadTrackId;
  float   itsSpeed;
  uchar   itsCarNum;
};

#endif


