#include "Train.h"

TTrain::TTrain(ushort aTrackId) :
  itsTrackId(aTrackId)
{
}

TTrain::TTrain(ushort aNum, ushort aTrackId) :
  itsNum(aNum),
  itsTrackId(aTrackId)
{
}

TTrain::~TTrain()
{
}

void TTrain::SetId(uchar aId)
{
  itsId = aId;
}

void TTrain::SetTrackId(ushort aTrackId)
{
  itsTrackId = aTrackId;
}

void TTrain::SetNum(ushort aNum)
{
  itsNum = aNum;
}

void TTrain::SetLocoType(ushort aLocoType)
{
  itsLocoType = aLocoType;
}

void TTrain::SetCarNum(uchar aCarNum)
{
  itsCarNum = aCarNum;
}

void TTrain::SetSpeed(float aSpeed)
{
  itsSpeed = aSpeed;
}

void TTrain::SetWhistle(uchar aWhistle)
{
  itsWhistle = aWhistle;
}

uchar TTrain::GetId() const
{
  return itsId;
}

ushort TTrain::GetTrackId() const
{
  return itsTrackId;
}

ushort TTrain::GetNum() const
{
  return itsNum;
}

ushort TTrain::GetLocoType() const
{
  return itsLocoType;
}

uchar TTrain::GetCarNum() const
{
  return itsCarNum;
}

float TTrain::GetSpeed() const
{
  return itsSpeed;
}

uchar TTrain::GetWhistle() const
{
  return itsWhistle;
}

