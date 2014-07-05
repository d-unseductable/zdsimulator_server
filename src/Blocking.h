#ifndef __BLOCKING_H__
#define __BLOCKING_H__

#include <vector.h>

#include "Svetofor.h"
#include "Train.h"

class TBlocking
{
public:
  TBlocking();
  ~TBlocking();

  void  SetAsc(bool aAsc);
  void  AddSvetofor(TSvetofor *aSvetofor);
  void  AddTrain(TTrain *aTrain);

  void  DeleteTrain(ushort aNum);

  void  Calculate();
  void  ReverseSv();

  bool      GetAsc() const;
  bool      IsTrainBetween(ushort aStartTrack, ushort aEndTrack) const;
  int       GetSvetoforNum() const;
  int       GetTrainNum() const;

  TSvetofor *GetSvetofor(uchar  aNum) const;
  TSvetofor *GetSvetoforById(ushort aId) const;
  TTrain    *GetTrain(uchar aNum) const;
  TTrain    *GetTrainByNum(ushort aNum) const;

private:
  bool                itsAsc;
  vector<TSvetofor*>  *itsSvVec;
  vector<TTrain*>     *itsTrVec;
};

#endif

