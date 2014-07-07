#ifndef __TRAIN_H__
#define __TRAIN_H__

#include "Types.h"

/*
 * TTrain class describes a train and its attributes for calculating
 * current route state
 */

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
  uchar   itsId;       // Train id
  ushort  itsTrackId;  // Track id
  ushort  itsNum;      // Train number
  ushort  itsLocoType; // Locomotive type
  uchar   itsCarNum;   // Number of cars
  float   itsSpeed;    // Current speed
  uchar   itsWhistle;  // Whistle state
};

#endif
