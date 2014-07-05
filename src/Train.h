#ifndef __TRAIN_H__
#define __TRAIN_H__

#include "Types.h"

class TTrain
{
public:
  TTrain(ushort aTrackId);
  TTrain(ushort aNum, ushort aTrackId);
  ~TTrain();

  void  SetId(uchar aId);
  void  SetTrackId(ushort aTrackId);
  void  SetNum(ushort aNum);
  void  SetLocoType(ushort aLocoType);
  void  SetCarNum(uchar aCarNum);
  void  SetSpeed(float aSpeed);
  void  SetWhistle(uchar aWhistle);

  uchar   GetId() const;
  ushort  GetTrackId() const;
  ushort  GetNum() const;
  ushort  GetLocoType() const;
  uchar   GetCarNum() const;
  float   GetSpeed() const;
  uchar   GetWhistle() const;

private:
  uchar   itsId;
  ushort  itsTrackId;
  ushort  itsNum;
  ushort  itsLocoType;
  uchar   itsCarNum;
  float   itsSpeed;
  uchar   itsWhistle;
};

#endif

