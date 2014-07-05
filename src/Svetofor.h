#ifndef __SVETOFOR_H__
#define __SVETOFOR_H__

#include "Types.h"

enum svType { ab_line, ab_entr, ab_exit, ab_rout };
enum svValue { svRed = 1, svYellow, svGreenY, svGreen, svYY = 20, svYbY, svYb };

class TSvetofor
{
public:
  TSvetofor();
  ~TSvetofor();

  void  SetId(ushort aId);
  void  SetName(char *aName);
  void  SetTrackId(ushort aTrackId);
  void  SetType(uchar aType);
  void  SetAttr(char aAttr);
  void  SetValue(uchar aValue);
  void  SetAutoOpen(bool aAutoOpen);
  void  SetForceOpen(bool aForceOpen);
  void  SetGone(bool aGone);

  ushort      GetId() const;
  ushort      GetTrackId() const;
  uchar       GetType() const;
  char        GetAttr() const;
  uchar       GetValue() const;
  bool        GetAutoOpen() const;
  bool        GetForceOpen() const;
  bool        GetGone() const;
  const char  *GetName() const;

private:
  ushort  itsId;
  char    itsAttr;
  char    itsName[7];
  ushort  itsTrackId;
  uchar   itsType;
  uchar   itsValue;
  bool    itsAutoOpen;
  bool    itsForceOpen;
  bool    itsGone;
};

#endif
