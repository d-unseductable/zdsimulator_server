#ifndef __GBLOCK_H__
#define __GBLOCK_H__

#include <vcl.h>

#include "Blocking.h"

struct TLine
{
  TPoint  itsStart;
  TPoint  itsEnd;
};

class TGBlock
{
public:
  TGBlock(TBlocking *aBlocking, TShape *aShape, TLine *itsLine);
  ~TGBlock();

  void SetTracks(ushort aStartTrack, ushort aEndTrack);
  void SetLine(TLine *aStart);

  void Show();

  TLine *GetLine() const;

private:
  TBlocking *itsBlocking;
  TLine     *itsLine;
  TShape    *itsShape;
  ushort    itsStartTrack;
  ushort    itsEndTrack;
};

#endif

