#ifndef __STRIP_H__
#define __STRIP_H__

class TStrip
{
public:
  TStrip();
  ~TStrip();

  void  SetPresTM(float aPresTM);
  void  SetHour(int aHour);
  void  SetMinute(int aMinute);
  void  SetEPK(bool aEPK);
  void  SetRed(bool aRed);
  void  SetWhite(bool aWhite);
  void  SetSpeed(float aSpeed);
  void  SetSpeedLimit(int aSpeedLimit);

  float GetPresTM() const;
  int   GetHour() const;
  int   GetMinute() const;
  bool  GetEPK() const;
  bool  GetRed() const;
  bool  GetWhite() const;
  float GetSpeed() const;
  int   GetSpeedLimit() const;

private:
  float itsPresTM;
  int   itsHour;
  int   itsMinute;
  bool  itsEPK;
  bool  itsRed;
  bool  itsWhite;
  float itsSpeed;
  int   itsSpeedLimit;
};

#endif

