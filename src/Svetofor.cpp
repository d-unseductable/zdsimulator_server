#include <string.h>

#include "Svetofor.h"

TSvetofor::TSvetofor() :
  itsAttr(0),
  itsValue(255),
  itsAutoOpen(false),
  itsForceOpen(false),
  itsGone(false)
{
}

TSvetofor::~TSvetofor()
{
}

void TSvetofor::SetId(ushort aId)
{
  itsId = aId;
}

void TSvetofor::SetName(char *aName)
{
  strncpy(itsName, aName, 6);
}

void TSvetofor::SetTrackId(ushort aTrackId)
{
  itsTrackId = aTrackId;
}

void TSvetofor::SetType(uchar aType)
{
  itsType = aType;
}

void TSvetofor::SetAttr(char aAttr)
{
  itsAttr = aAttr;
}

void TSvetofor::SetValue(uchar aValue)
{
  itsValue = aValue;
}

void TSvetofor::SetAutoOpen(bool aAutoOpen)
{
  itsAutoOpen = aAutoOpen;
}

void TSvetofor::SetForceOpen(bool aForceOpen)
{
  itsForceOpen = aForceOpen;
}

void TSvetofor::SetGone(bool aGone)
{
  itsGone = aGone;
}

ushort TSvetofor::GetId() const
{
  return itsId;
}

const char *TSvetofor::GetName() const
{
  return itsName;
}

ushort TSvetofor::GetTrackId() const
{
  return itsTrackId;
}

uchar TSvetofor::GetType() const
{
  return itsType;
}
char TSvetofor::GetAttr() const
{
  return itsAttr;
}

uchar TSvetofor::GetValue() const
{
  return itsValue;
}

bool TSvetofor::GetAutoOpen() const
{
  return itsAutoOpen;
}

bool TSvetofor::GetForceOpen() const
{
  return itsForceOpen;
}

bool TSvetofor::GetGone() const
{
  return itsGone;
}
