#ifndef __BLOCKING_H__
#define __BLOCKING_H__

#include <vector.h>

#include "Svetofor.h"
#include "Train.h"

/*
 * TBlocking describe the whole blocking system of a route.
 * Each route has two blockings - the odd and the even.
 */
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
  bool                itsAsc;    // Ascending or descending blocking
  vector<TSvetofor*>  *itsSvVec; // Vector of signals
  vector<TTrain*>     *itsTrVec; // Vector of trains
};

#endif
