#include "Svetofor.h"
#include "Blocking.h"

TBlocking::TBlocking()
{
  itsSvVec = new vector<TSvetofor*>;
  itsTrVec = new vector<TTrain*>;

  itsSvVec->clear();
  itsTrVec->clear();
}

TBlocking::~TBlocking()
{
  delete itsSvVec;
  delete itsTrVec;
}

void TBlocking::SetAsc(bool aAsc)
{
  itsAsc = aAsc;
}

void TBlocking::AddSvetofor(TSvetofor *aSvetofor)
{
  itsSvVec->push_back(aSvetofor);
}

void TBlocking::AddTrain(TTrain *aTrain)
{
  itsTrVec->push_back(aTrain);
}

void TBlocking::DeleteTrain(ushort aNum)
{
  vector<TTrain*>::iterator Tr;

  for(Tr = itsTrVec->begin(); Tr < itsTrVec->end(); Tr++)
  {
    if((*Tr)->GetNum() == aNum)
    {
      itsTrVec->erase(Tr);
      return;
    }
  }
}

bool TBlocking::GetAsc() const
{
  return itsAsc;
}

bool TBlocking::IsTrainBetween(ushort aStartTrack, ushort aEndTrack) const
{
  vector<TTrain*>::const_iterator Tr;

  for(Tr = itsTrVec->begin(); Tr < itsTrVec->end(); Tr++)
    if(((*Tr)->GetTrackId() >= aStartTrack) && ((*Tr)->GetTrackId() <= aEndTrack))
      return true;

  return false;
}

int TBlocking::GetSvetoforNum() const
{
  return itsSvVec->size();
}

int TBlocking::GetTrainNum() const
{
  return itsTrVec->size();
}

TSvetofor *TBlocking::GetSvetofor(uchar aNum) const
{
  return (*itsSvVec)[aNum];
}

TSvetofor *TBlocking::GetSvetoforById(ushort aId) const
{
  vector<TSvetofor*>::const_iterator Sv;

  for(Sv = itsSvVec->begin(); Sv < itsSvVec->end(); Sv++)
    if((*Sv)->GetId() == aId)
      return (*Sv);

  return 0;
}

TTrain *TBlocking::GetTrain(uchar aNum) const
{
  return (*itsTrVec)[aNum];
}

TTrain *TBlocking::GetTrainByNum(ushort aNum) const
{
  vector<TTrain*>::const_iterator Tr;

  for(Tr = itsTrVec->begin(); Tr < itsTrVec->end(); Tr++)
    if((*Tr)->GetNum() == aNum)
      return (*Tr);

  return 0;
}

void TBlocking::ReverseSv()
{
  int       i;
  int       Num;
  TSvetofor *Sv;

  Num = GetSvetoforNum();
  for(i = 0; i < Num / 2; i++)
  {
    Sv = (*itsSvVec)[i];
    (*itsSvVec)[i] = (*itsSvVec)[Num - i - 1];
    (*itsSvVec)[Num - i - 1] = Sv;
  }
}

void TBlocking::Calculate()
{
  int i;
  int j;
  int CurTrackId;
  int NextTrackId;

  vector<TSvetofor*>::reverse_iterator  Current;
  vector<TSvetofor*>::reverse_iterator  Cur;
  vector<TSvetofor*>::reverse_iterator  Next;
  vector<TTrain*>::const_iterator       Tr;

  for(Current = itsSvVec->rbegin(); Current < itsSvVec->rend(); Current++)
  {
    (*Current)->SetValue(255);

    Next = Current - 1;

    if(Current != itsSvVec->rbegin())
    {
      CurTrackId = (*Current)->GetTrackId();
      NextTrackId = (*Next)->GetTrackId();

      for(Tr = itsTrVec->begin(); Tr < itsTrVec->end(); Tr++)
      {
        if(itsAsc)
        {
          if(((*Tr)->GetTrackId() >= CurTrackId) && ((*Tr)->GetTrackId() <= NextTrackId))
          {
            (*Current)->SetValue(svRed);

            if((*Current)->GetForceOpen())
              (*Current)->SetForceOpen(false);

            break;
          }
        }
        else
        {
          if(((*Tr)->GetTrackId() <= CurTrackId) && ((*Tr)->GetTrackId() >= NextTrackId))
          {
            (*Current)->SetValue(svRed);

            if((*Current)->GetForceOpen())
              (*Current)->SetForceOpen(false);

            break;
          }
        }
      }

      if(((*Current)->GetValue() == 255) && ((*Current)->GetAutoOpen() || (*Current)->GetForceOpen()))
      {
        if(((*Current)->GetAttr() == '4') && ((*Next)->GetValue() == svYellow))
        {
          (*Current)->SetValue(svGreenY);
        }
        else if((*Current)->GetAttr() == 'Y')
        {
          if((*Next)->GetValue() == svRed)
            (*Current)->SetValue(svYY);
          else
            (*Current)->SetValue(svYbY);
        }
        else if((*Next)->GetValue() == svRed)
        {
          (*Current)->SetValue(svYellow);
        }
        else if(((*Next)->GetValue() == svYY) || ((*Next)->GetValue() == svYbY))
        {
          (*Current)->SetValue(svYb);
        }
      }
      else
      {
        (*Current)->SetValue(svRed);
      }
    }
    else
    {
      if((*Current)->GetForceOpen())
        (*Current)->SetValue(svGreen);
      else
        (*Current)->SetValue(svRed);
    }

    if((*Current)->GetValue() == 255)
      (*Current)->SetValue(svGreen);
  }
}

