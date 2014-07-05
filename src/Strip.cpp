#include "Strip.h"

TStrip::TStrip()
{
}

TStrip::~TStrip()
{
}

void TStrip::SetPresTM(float aPres)
{
  itsPresTM = aPres;
}

void TStrip::SetHour(int aHour)
{
  itsHour = aHour;
}

void TStrip::SetMinute(int aMinute)
{
  itsMinute = aMinute;
}

void TStrip::SetEPK(bool aEPK)
{
  itsEPK = aEPK;
}

void TStrip::SetRed(bool aRed)
{
  itsRed = aRed;
}

void TStrip::SetWhite(bool aWhite)
{
  itsWhite = aWhite;
}
