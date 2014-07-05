#ifndef __GSVETOFOR_H__
#define __GSVETOFOR_H__

#include <vcl.h>

#include "Svetofor.h"

class TGSvetofor
{
public:
  TGSvetofor();
  TGSvetofor(TSvetofor *aSvetofor, TForm *itsParent);
  ~TGSvetofor();

  void  SetTop(int aTop);
  void  SetLeft(int aLeft);
  void  SetDTop(int aDTop);
  void  SetDLeft(int aDLeft);
  void  SetSvetofor(TSvetofor *aSvetofor);
  void  SetParent(TForm *aParent);
  void  SetImage(TImage *aImage);
  void  SetLabel(TLabel *aLabel);
  void  SetOpenPath(const char *aPath);
  void  SetClosedPath(const char *aPath);
  void  SetOpen(bool aOpen);

  void  Create();
  void  Show();

  int       GetTop() const;
  int       GetLeft() const;
  int       GetDTop() const;
  int       GetDLeft() const;
  TSvetofor *GetSvetofor() const;
  TForm     *GetParent() const;
  TImage    *GetImage() const;
  TLabel    *GetLabel() const;
  char      *GetOpenPath() const;
  char      *GetClosedPath() const;
  bool      GetOpen() const;

private:
  int       itsTop;
  int       itsLeft;
  int       itsDTop;
  int       itsDLeft;
  TSvetofor *itsSvetofor;
  TForm     *itsParent;
  TImage    *itsImage;
  TLabel    *itsLabel;
  char      *itsOpenPath;
  char      *itsClosedPath;
  bool      itsOpen;
  bool      itsChanged;
};

#endif
