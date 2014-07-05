#include "GBlock.h"

TGBlock::TGBlock(TBlocking *aBlocking, TShape *aShape, TLine *aLine) :
  itsBlocking(aBlocking),
  itsShape(aShape),
  itsLine(aLine)
{
}

TGBlock::~TGBlock()
{
  delete itsLine;
  delete itsShape;
}

void TGBlock::SetTracks(ushort aStartTrack, ushort aEndTrack)
{
  itsStartTrack = aStartTrack;
  itsEndTrack = aEndTrack;
}

void TGBlock::SetLine(TLine *aLine)
{
  delete itsLine;

  itsLine = aLine;
}

TLine *TGBlock::GetLine() const
{
  return itsLine;
}

void TGBlock::Show()
{
/*
  if(itsBlocking->IsTrainBetween(itsStartTrack, itsEndTrack))
  {
    itsCanvas->Pen->Color = clRed;
    itsCanvas->Pen->Style = psSolid;
    itsCanvas->Pen->Width = 2;

    itsCanvas->MoveTo(itsLine->itsStart.x, itsLine->itsStart.y);
    itsCanvas->LineTo(itsLine->itsEnd.x, itsLine->itsEnd.y);
  }
*/
  if(itsBlocking->IsTrainBetween(itsStartTrack, itsEndTrack))
    itsShape->Visible = true;
  else
    itsShape->Visible = false;
}

