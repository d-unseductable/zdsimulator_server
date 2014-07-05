#include <string.h>

#include "GSvetofor.h"

TGSvetofor::TGSvetofor() :
  itsDTop(0),
  itsDLeft(0),
  itsSvetofor(0),
  itsParent(0),
  itsImage(0),
  itsLabel(0),
  itsOpenPath(0),
  itsClosedPath(0),
  itsOpen(2)
{
}

TGSvetofor::TGSvetofor(TSvetofor *aSvetofor, TForm *aParent) :
  itsDTop(0),
  itsDLeft(0),
  itsSvetofor(aSvetofor),
  itsParent(aParent),
  itsImage(0),
  itsLabel(0),
  itsOpenPath(0),
  itsClosedPath(0),
  itsOpen(2)
{
}

TGSvetofor::~TGSvetofor()
{
  delete itsImage;
  delete itsLabel;
  delete itsClosedPath;
  delete itsOpenPath;
}

void TGSvetofor::SetTop(int aTop)
{
  itsTop = aTop;
}

void TGSvetofor::SetLeft(int aLeft)
{
  itsLeft = aLeft;
}

void TGSvetofor::SetDTop(int aDTop)
{
  itsDTop = aDTop;
}

void TGSvetofor::SetDLeft(int aDLeft)
{
  itsDLeft = aDLeft;
}

void TGSvetofor::SetSvetofor(TSvetofor *aSvetofor)
{
  itsSvetofor = aSvetofor;
}

void TGSvetofor::SetParent(TForm *aParent)
{
  itsParent = aParent;
}

void TGSvetofor::SetImage(TImage *aImage)
{
  itsImage = aImage;
}

void TGSvetofor::SetLabel(TLabel *aLabel)
{
  itsLabel = aLabel;
}

void TGSvetofor::SetOpenPath(const char *aPath)
{
  if(itsOpenPath)
    delete itsOpenPath;

  itsOpenPath = new char[50];

  strcpy(itsOpenPath, aPath);
}

void TGSvetofor::SetClosedPath(const char *aPath)
{
  if(itsClosedPath)
    delete itsClosedPath;

  itsClosedPath = new char[50];

  strcpy(itsClosedPath, aPath);
}

void TGSvetofor::SetOpen(bool aOpen)
{
  if(itsOpen != aOpen)
  {
    itsOpen = aOpen;
    itsChanged = true;
  }
}

int TGSvetofor::GetTop() const
{
  return itsTop;
}

int TGSvetofor::GetLeft() const
{
  return itsLeft;
}

int TGSvetofor::GetDTop() const
{
  return itsDTop;
}

int TGSvetofor::GetDLeft() const
{
  return itsDLeft;
}

TSvetofor *TGSvetofor::GetSvetofor() const
{
  return itsSvetofor;
}

TForm *TGSvetofor::GetParent() const
{
  return itsParent;
}

TImage *TGSvetofor::GetImage() const
{
  return itsImage;
}

TLabel *TGSvetofor::GetLabel() const
{
  return itsLabel;
}

char *TGSvetofor::GetOpenPath() const
{
  return itsOpenPath;
}

char *TGSvetofor::GetClosedPath() const
{
  return itsClosedPath;
}

bool TGSvetofor::GetOpen() const
{
  return itsOpen;
}

void TGSvetofor::Create()
{
  if(!itsParent)
    return;

  itsImage = new TImage(itsParent);
  itsLabel = new TLabel(itsParent);

  itsImage->Parent = itsParent;
  itsImage->Name = "GSvet" + IntToStr(itsSvetofor->GetId());
  itsImage->Left = itsLeft;
  itsImage->Top = itsTop;
  itsImage->Width = 30;
  itsImage->Height = 17;

  itsLabel->Parent = itsParent;
  itsLabel->Name = "GSvetLabel" + IntToStr(itsSvetofor->GetId());
  itsLabel->Left = itsLeft + itsDLeft;
  itsLabel->Top = itsTop + itsDTop;
  itsLabel->Transparent = true;
  itsLabel->Caption = itsSvetofor->GetName();
  itsLabel->Font->Name = "Arial";
  itsLabel->Font->Style = TFontStyles() << fsBold;
  itsLabel->Font->Size = 6;
}

void TGSvetofor::Show()
{
  bool  SvOpen;

  if(itsSvetofor->GetValue() == 1)
    SvOpen = false;
  else
    SvOpen = true;

  if(itsOpen != SvOpen)
  {
    if(SvOpen)
      itsImage->Picture->LoadFromFile(itsOpenPath);
    else
      itsImage->Picture->LoadFromFile(itsClosedPath);

    itsOpen = SvOpen;
  }
}

