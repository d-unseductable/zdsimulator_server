//---------------------------------------------------------------------------
#include <fstream.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "Blocking.h"
#include "NetStruct.h"
#include "GSvetofor.h"
#include "GBlock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TBlocking *BlockN;
TBlocking *BlockC;
//---------------------------------------------------------------------------
void TForm1::ReadSvetofors()
{
  int       i;
  int       j;
  ushort    SvId;
  ushort    TrackId;
  uchar     Type;
  char      Str[256];
  char      sType[8];
  char      Name[7];
  char      Attr;
  int       Pos;
  int       Num;
  int       ForceNum;
  TSvetofor *Sv;

  int       Top;
  int       Left;
  int       Width;
  int       Height;
  int       Space;
  int       SpaceVert;
  int       RowHeight;
  int       RowCount;

  AnsiString  aStr;
  AnsiString  aTrackId;
  AnsiString  aName;
  AnsiString  aType;
  AnsiString  aAttr;

  Top = 10;
  Left = 10;
  Height = 15;
  Width = 15;
  Space = 20;
  SpaceVert = 40;
  RowHeight = 100;
  RowCount = 25;

  ifstream  isn("svetofor1.dat");
  ifstream  isc("svetofor2.dat");

  ForceNum = 0;
  SvId = 1;

  while(!isn.eof())
  {
    isn.getline(Str, 255);
    aStr = Str;

    if(aStr[1] == ';')
      continue;

    Pos = aStr.Pos("\t");
    aTrackId = aStr.SubString(1, Pos - 1);
    TrackId = StrToInt(aTrackId);
    aStr = aStr.SubString(Pos + 1, aStr.Length() - Pos);

    Pos = aStr.Pos("\t");
    aType = aStr.SubString(1, Pos - 1);
    aStr = aStr.SubString(Pos + 1, aStr.Length() - Pos);

    Pos = aStr.Pos("\t");

    if(!Pos)
    {
      aName = aStr;
      Attr = 0;
    }
    else
    {
      aName = aStr.SubString(1, Pos - 1);
      Attr = aStr.SubString(Pos + 1, aStr.Length() - Pos)[1];
    }

    strncpy(Name, aName.c_str(), 6);

    Sv = new TSvetofor;

    ForceNum++;

    if(aType == "ab_rout")
    {
      Type = ab_rout;
    }
    else if(aType == "ab_exit")
    {
      Type = ab_exit;
    }
    else if(aType == "ab_entr")
    {
      Type = ab_entr;
    }
    else if(aType ==  "ab_line")
    {
      Type = ab_line;
      Sv->SetAutoOpen(true);
      ForceNum--;
    }

    Sv->SetId(SvId);
    Sv->SetTrackId(TrackId);
    Sv->SetName(Name);
    Sv->SetType(Type);
    Sv->SetAttr(Attr);

    BlockN->AddSvetofor(Sv);

    SvId++;
  }

  isn.close();

  Num = BlockN->GetSvetoforNum();

  ForceNum = 0;

  while(!isc.eof())
  {
    isc.getline(Str, 255);
    aStr = Str;

    if(aStr[1] == ';')
      continue;

    Pos = aStr.Pos("\t");
    aTrackId = aStr.SubString(1, Pos - 1);
    TrackId = StrToInt(aTrackId);
    aStr = aStr.SubString(Pos + 1, aStr.Length() - Pos);

    Pos = aStr.Pos("\t");
    aType = aStr.SubString(1, Pos - 1);
    aStr = aStr.SubString(Pos + 1, aStr.Length() - Pos);

    Pos = aStr.Pos("\t");

    if(!Pos)
    {
      aName = aStr;
      Attr = 0;
    }
    else
    {
      aName = aStr.SubString(1, Pos - 1);
      Attr = aStr.SubString(Pos + 1, aStr.Length() - Pos)[1];
    }

    strncpy(Name, aName.c_str(), 6);

    Sv = new TSvetofor;

    ForceNum++;

    if(aType == "ab_rout")
    {
      Type = ab_rout;
    }
    else if(aType == "ab_exit")
    {
      Type = ab_exit;
    }
    else if(aType == "ab_entr")
    {
      Type = ab_entr;
    }
    else if(aType ==  "ab_line")
    {
      Type = ab_line;
      Sv->SetAutoOpen(true);
      ForceNum--;
    }

    Sv->SetId(SvId);
    Sv->SetTrackId(TrackId);
    Sv->SetName(Name);
    Sv->SetType(Type);
    Sv->SetAttr(Attr);

    BlockC->AddSvetofor(Sv);

    SvId++;
  }

  Num = BlockC->GetSvetoforNum();

  isc.close();
}

void TForm1::ReadTrains()
{
  ushort  TrackId;
  TTrain  *Tr;

  ifstream  isn("train1.dat");
  ifstream  isc("train2.dat");

  while(!isn.eof())
  {
    isn >> TrackId;

    Tr = new TTrain(TrackId);

    BlockN->AddTrain(Tr);
  }

  isn.close();

  while(!isc.eof())
  {
    isc >> TrackId;

    Tr = new TTrain(TrackId);

    BlockC->AddTrain(Tr);
  }

  isc.close();
}

void TForm1::ReadBlocks()
{
  int       Count;
  ushort    StartTrack;
  ushort    EndTrack;
  TLine     *Line;
  TGBlock   *Block;
  TShape    *Shape;

  ifstream  isn("block1.dat");
  ifstream  isc("block2.dat");

  Count = 0;

  while(!isn.eof())
  {
    Line = new TLine;
    Shape = new TShape(this);

    isn >> StartTrack;
    isn >> EndTrack;
    isn >> Line->itsStart.x;
    isn >> Line->itsStart.y;
    isn >> Line->itsEnd.x;
    isn >> Line->itsEnd.y;

    Shape->Name = "Shape" + IntToStr(Count);
    Shape->Parent = this;
    Shape->Visible = false;
    Shape->Left = Line->itsStart.x;
    Shape->Top = Line->itsStart.y - 1;
    Shape->Width = Line->itsEnd.x - Line->itsStart.x;
    Shape->Height = 3;
    Shape->Pen->Style = psClear;
    Shape->Brush->Style = bsSolid;
    Shape->Brush->Color = clRed;

    Block = new TGBlock(BlockN, Shape, Line);

    if(StartTrack < EndTrack)
      Block->SetTracks(StartTrack, EndTrack);
    else
      Block->SetTracks(EndTrack, StartTrack);
    
    GBlockVec->push_back(Block);

    Count++;
  }

  while(!isc.eof())
  {
    Line = new TLine;
    Shape = new TShape(this);

    isc >> StartTrack;
    isc >> EndTrack;
    isc >> Line->itsStart.x;
    isc >> Line->itsStart.y;
    isc >> Line->itsEnd.x;
    isc >> Line->itsEnd.y;

    Shape->Name = "Shape" + IntToStr(Count);
    Shape->Parent = this;
    Shape->Visible = false;
    Shape->Left = Line->itsStart.x;
    Shape->Top = Line->itsStart.y - 1;
    Shape->Width = Line->itsEnd.x - Line->itsStart.x;
    Shape->Height = 3;
    Shape->Pen->Style = psClear;
    Shape->Brush->Style = bsSolid;
    Shape->Brush->Color = clRed;

    Block = new TGBlock(BlockC, Shape, Line);

    if(StartTrack < EndTrack)
      Block->SetTracks(StartTrack, EndTrack);
    else
      Block->SetTracks(EndTrack, StartTrack);

    GBlockVec->push_back(Block);

    Count++;
  }

  isn.close();
  isc.close();
}

void TForm1::ShowSvetofors()
{
/*
  int       i;
  int       Num;
  uchar     Value;
  TColor    Color;
  TSvetofor *Sv;
*/
  vector<TGSvetofor*>::const_iterator GSvCur;

  for(GSvCur = GSvVec->begin(); GSvCur < GSvVec->end(); GSvCur++)
    (*GSvCur)->Show();
/*
  Num = BlockN->GetSvetoforNum();

  for(i = 0; i < Num; i++)
  {
    Sv = BlockN->GetSvetofor(i);

    Value = Sv->GetValue();

    switch(Value)
    {
      case svRed:
        Color = clRed;
        break;
      case svYellow:
        Color = clYellow;
        break;
      case svGreenY:
        Color = clLime;
        break;
      case svGreen:
        Color = clGreen;
        break;
      case svYY:
        Color = clBlue;
        break;
      case svYbY:
        Color = clAqua;
        break;
      case svYb:
        Color = clPurple;
        break;
    }
  }

  Num = BlockC->GetSvetoforNum();

  for(i = 0; i < Num; i++)
  {
    Sv = BlockC->GetSvetofor(i);

    Value = Sv->GetValue();

    switch(Value)
    {
      case svRed:
        Color = clRed;
        break;
      case svYellow:
        Color = clYellow;
        break;
      case svGreenY:
        Color = clLime;
        break;
      case svGreen:
        Color = clGreen;
        break;
      case svYY:
        Color = clBlue;
        break;
      case svYbY:
        Color = clAqua;
        break;
      case svYb:
        Color = clPurple;
        break;
    }
  }
*/
}

void TForm1::ShowTrains()
{
  int     i;
  int     j;
  int     Num;
  ushort  Number;

  vector<TNTrain*>::const_iterator  Train;

  TTrain  *Tr;

  Num = BlockN->GetTrainNum();
  TrainGrid->RowCount = Num + BlockC->GetTrainNum();

  for(i = 0; i < TrainGrid->RowCount; i++)
  {
    TrainGrid->Cells[0][i] = "";
    TrainGrid->Cells[1][i] = "";
    TrainGrid->Cells[2][i] = "";
  }

  for(i = 0; i < Num; i++)
  {
    Tr = BlockN->GetTrain(i);

    Train = FindTrainByNum(Tr->GetNum());

    TrainGrid->Cells[0][i] = Tr->GetNum();
    TrainGrid->Cells[1][i] = Tr->GetTrackId();

    if(!(*Train)->itsThread || !(*Train)->itsThread->Connection->Connected())
      TrainGrid->Cells[2][i] = "!!!";
  }

  Num = BlockC->GetTrainNum();
  for(j = i, i = 0; i < Num; i++, j++)
  {
    Tr = BlockC->GetTrain(i);

    Train = FindTrainByNum(Tr->GetNum());

    TrainGrid->Cells[0][j] = Tr->GetNum();
    TrainGrid->Cells[1][j] = Tr->GetTrackId();

    if(!(*Train)->itsThread)
      TrainGrid->Cells[2][i] = "!!!";
  }
}

void TForm1::ShowBlocks()
{
  vector<TGBlock*>::const_iterator GBlockCur;

  for(GBlockCur = GBlockVec->begin(); GBlockCur < GBlockVec->end(); GBlockCur++)
    (*GBlockCur)->Show();
}

void TForm1::FindVisibles()
{
  int       i;
  int       j;
  int       NumN;
  int       NumC;
  int a, b;
  TVisibles *Visibles;

  VisibleVec->clear();

  NumN = BlockN->GetTrainNum();
  NumC = BlockC->GetTrainNum();

  for(i = 0; i < NumN; i++)
  {
    for(j = 0; j < NumC; j++)
    {
      if(abs(BlockN->GetTrain(i)->GetTrackId() - BlockC->GetTrain(j)->GetTrackId()) <= 25)
      {
        Visibles = new TVisibles;

        Visibles->itsTrain[0] = BlockN->GetTrain(i);
        Visibles->itsTrain[1] = BlockC->GetTrain(j);

        VisibleVec->push_back(Visibles);
      }
    }
  }
}

__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
  Loaded = false;
  TrainVec = new vector<TNTrain*>;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  int i;

  BlockN->Calculate();
  BlockC->Calculate();
  
  ShowSvetofors();
  ShowTrains();
  ShowBlocks();

  FindVisibles();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SvShapeMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int         Number;
  char        Direction;
  AnsiString  Name;
  TShape      *Shape;

  Shape = dynamic_cast<TShape*>(Sender);

  Name = Shape->Name;
  Direction = Name[8];

  Name = Name.SubString(9, 3);
  Number = StrToInt(Name);

  if(Direction == 'C')
    BlockC->GetSvetofor(Number)->SetForceOpen(!BlockC->GetSvetofor(Number)->GetForceOpen());
  else
    BlockN->GetSvetofor(Number)->SetForceOpen(!BlockN->GetSvetofor(Number)->GetForceOpen());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerExecute(TIdPeerThread *AThread)
{
  int     i;
  int     j;
  int     Res;

  uchar   Req;
  uchar   Code;
  uchar   Hour;
  uchar   Minute;
  ushort  SvNum;
  ushort  SvNNum;
  ushort  SvCNum;
  ushort  TrNum;

  AnsiString    Str;
  TrSp          TrSps;
  TPoint4       Coords;
  TPoint4       Coords0;

  TTrain        *Tr;
  TTrain        *Traffic;

  TNCoords      *CoordsSt;
  TNConnect     *ConnSt;
  TNTrain       *NetTrain;
  TNTraf        *NetTraffic;
  uchar         *NetSv;

  vector<TVisibles*>::const_iterator  Vis;

  AThread->Connection->ReadBuffer((void *)&Req, 1);

  SvNNum = BlockN->GetSvetoforNum();
  SvCNum = BlockC->GetSvetoforNum();
  SvNum = SvNNum + SvCNum;

  if(Req == 1)
  {
    ConnSt = new TNConnect;

    AThread->Connection->ReadBuffer((void *)ConnSt, sizeof(TNConnect));

    if(SvNum != ConnSt->itsSigNum)
    {
      Code = 2;
    }
    else if(BlockN->GetTrainByNum(ConnSt->itsTrainNum) || BlockC->GetTrainByNum(ConnSt->itsTrainNum))
    {
      Str = "Внимание! Поезд " + IntToStr(ConnSt->itsTrainNum) + " пытается переподключиться. Разрешить?";
      Res = MessageBox(Form1->Handle, Str.c_str(),
        "Предупреждение", MB_YESNO | MB_ICONQUESTION);

      if(Res == ID_YES)
      {
        Tr = new TTrain(ConnSt->itsTrainNum, ConnSt->itsTrackId);
        Tr->SetLocoType(ConnSt->itsLocoType);
        Tr->SetCarNum(ConnSt->itsCarNum);

        (*FindTrainByNum(ConnSt->itsTrainNum))->itsThread = AThread;

        Code = 200;
      }
      else
      {
        AThread->Connection->Disconnect();
      }
    }
    else
    {
      Str = "Поезд " + IntToStr(ConnSt->itsTrainNum) + " пытается подключиться. Разрешить?";
      Res = MessageBox(Form1->Handle, Str.c_str(),
        "Предупреждение", MB_YESNO | MB_ICONQUESTION);

      if(Res == ID_YES)
      {
        Tr = new TTrain(ConnSt->itsTrainNum, ConnSt->itsTrackId);
        Tr->SetLocoType(ConnSt->itsLocoType);
        Tr->SetCarNum(ConnSt->itsCarNum);

        if(ConnSt->itsDirection == 1)
          BlockN->AddTrain(Tr);
        else
          BlockC->AddTrain(Tr);

        NetTrain = new TNTrain;
        NetTrain->itsNum = ConnSt->itsTrainNum;
        NetTrain->itsThread = AThread;

        TrainVec->push_back(NetTrain);

        Code = 200;
      }
      else
      {
        AThread->Connection->Disconnect();
      }
    }

    ConnSt->itsSigNum;
    ConnSt->itsTrainNum;
    ConnSt->itsTrackId;
    ConnSt->itsDirection;
    ConnSt->itsLocoType;
    ConnSt->itsCarNum;

    AThread->Connection->WriteBuffer((void *)&Code, sizeof(uchar));

    if(Code == 200)
    {
      Hour = StrToInt(HourEdit->Text);
      Minute = StrToInt(MinuteEdit->Text);

      AThread->Connection->WriteBuffer((void *)&Hour, sizeof(uchar));
      AThread->Connection->WriteBuffer((void *)&Minute, sizeof(uchar));
    }

    delete ConnSt;
  }
  else if(Req == 2)
  {
    AThread->Connection->ReadBuffer((void *)&TrNum, sizeof(TrNum));

    BlockC->DeleteTrain(TrNum);
    BlockN->DeleteTrain(TrNum);

    TrainVec->erase(FindTrainByNum(TrNum));

    AThread->Connection->Disconnect();
  }
  else if(Req == 3)
  {
    NetSv = new uchar[SvNum];
    CoordsSt = new TNCoords;
    NetTraffic = new TNTraf;

    AThread->Connection->ReadBuffer((void *)CoordsSt, sizeof(TNCoords));

    Tr = BlockC->GetTrainByNum(CoordsSt->itsTrainNum);
    if(!Tr)
      Tr = BlockN->GetTrainByNum(CoordsSt->itsTrainNum);

    Tr->SetTrackId(CoordsSt->itsHeadTrackId);
    Tr->SetSpeed(CoordsSt->itsSpeed);

    for(i = 0; i < SvNNum; i++)
    {
      NetSv[i] = BlockN->GetSvetofor(i)->GetValue();
    }

    for(j = i, i = 0; i < SvCNum; i++, j++)
    {
      NetSv[j] = BlockC->GetSvetofor(i)->GetValue();
    }

    AThread->Connection->WriteBuffer((void *)NetSv, sizeof(uchar) * SvNum, true);

    Traffic = 0;

    for(Vis = VisibleVec->begin(); Vis < VisibleVec->end(); Vis++)
    {
      if((*Vis)->itsTrain[0] == Tr)
        Traffic = (*Vis)->itsTrain[1];
      else if((*Vis)->itsTrain[1] == Tr)
        Traffic = (*Vis)->itsTrain[0];
    }

    if(!Traffic)
    {
      NetTraffic->itsTrainNum = 0;
    }
    else
    {
      NetTraffic->itsTrainNum = Traffic->GetNum();
      NetTraffic->itsLocoType = Traffic->GetLocoType();
      NetTraffic->itsCarNum = Traffic->GetCarNum();
      NetTraffic->itsHeadTrackId = Traffic->GetTrackId();
      NetTraffic->itsSpeed = Traffic->GetSpeed();
    }

    AThread->Connection->WriteBuffer((void *)NetTraffic, sizeof(TNTraf), true);

    delete    CoordsSt;
    delete    NetTraffic;
    delete[]  NetSv;
  }
  else if(Req == 19)
  {
    Str = AThread->Connection->ReadLn("\n");
    ShowMessage(Str);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FileLoadItemClick(TObject *Sender)
{
  bool        DirectN;
  int         Id;
  int         Top;
  int         Left;
  char        *PicPath;

  TGSvetofor  *GSv;
  TSvetofor   *SvCur;

  ifstream    is("kiev-kazatin.map");

  BlockN = new TBlocking;
  BlockC = new TBlocking;

  GSvVec = new vector<TGSvetofor*>;
  GBlockVec = new vector<TGBlock*>;
  VisibleVec = new vector<TVisibles*>;

  ShapesVec = new vector<TShape*>;

  BlockN->SetAsc(true);
  BlockC->SetAsc(false);

  StatusBar->SimpleText = "Загрузка...";

  ReadSvetofors();
  ReadBlocks();
//  ReadTrains();

  PicPath = new char[50];
  is >> PicPath;

  PultImage->Picture->LoadFromFile(PicPath);

  while(!is.eof())
  {
    is >> Id;
    is >> Left;
    is >> Top;

    DirectN = true;
    SvCur = BlockN->GetSvetoforById(Id);

    if(!SvCur)
    {
      SvCur = BlockC->GetSvetoforById(Id);
      DirectN = false;
    }

    GSv = new TGSvetofor(SvCur, this);

    GSv->SetTop(Top);
    GSv->SetLeft(Left);

    if(DirectN)
    {
      GSv->SetClosedPath("sv_n_cl.bmp");
      GSv->SetOpenPath("sv_n_op.bmp");
      GSv->SetDTop(-2);
      GSv->SetDLeft(-8);
    }
    else
    {
      GSv->SetClosedPath("sv_c_cl.bmp");
      GSv->SetOpenPath("sv_c_op.bmp");
      GSv->SetDTop(-2);
      GSv->SetDLeft(20);
    }
    
    GSv->Create();
    GSv->GetImage()->OnClick = GSvClick;

    GSvVec->push_back(GSv);
  }

  ShowSvetofors();

  Timer1->Enabled = true;
  TimerBg->Enabled = true;

  StatusBar->SimpleText = "";
  RouteName = "Киев-Казатин";

  Loaded = true;
  FileLoadItem->Enabled = false;
  FileUnloadItem->Enabled = true;

  NetMenu->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FileUnloadItemClick(TObject *Sender)
{
  int i;
  int NumN;
  int NumC;

  vector<TGSvetofor*>::iterator CurGSv;

  if(Server->Active)
  {
    ShowMessage("Деактивируйте сетевое подключение");
    return;
  }

  if(Loaded)
  {
    NumN = BlockN->GetSvetoforNum();
    NumC = BlockC->GetSvetoforNum();

    Timer1->Enabled = false;
    TimerBg->Enabled = false;

    for(CurGSv = GSvVec->begin(); CurGSv < GSvVec->end(); CurGSv++)
      delete (*CurGSv);

    GSvVec->clear();
    GBlockVec->clear();
//    ShapeVec->clear();

    delete GSvVec;
    delete GBlockVec;
    delete VisibleVec;
//    delete ShapeVec;

    delete BlockN;
    delete BlockC;

    Paint();

    Loaded = false;

    FileLoadItem->Enabled = true;
    FileUnloadItem->Enabled = false;

    NetMenu->Enabled = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NetActivateItemClick(TObject *Sender)
{
  AnsiString  IP;
/*
  IPWatch->Active = true;
  IPWatch->ForceCheck();
  IP = IPWatch->CurrentIP;
  IPWatch->Active = false;

  IP = IPEdit->Text;
  Server->Bindings->Add();
  Server->Bindings->Items[0]->IP = IP;
  Server->Bindings->Items[0]->Port = StrToInt(PortEdit->Text);
*/
  Server->DefaultPort = StrToInt(PortEdit->Text);

  Server->Active = true;
  NetActivateItem->Enabled = false;
  NetDeactivateItem->Enabled = true;

  StatusBar->Panels->Items[0]->Text = "Подключено";
  StatusBar->Panels->Items[1]->Text = IP;

  TimerTime->Enabled = true;
  HourEdit->Enabled = false;
  MinuteEdit->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NetDeactivateItemClick(TObject *Sender)
{
  Server->Active = false;
  NetActivateItem->Enabled = true;
  NetDeactivateItem->Enabled = false;

  Server->Bindings->Clear();

  VisibleVec->clear();

  TimerTime->Enabled = false;
  HourEdit->Enabled = true;
  MinuteEdit->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FileExitItemClick(TObject *Sender)
{
  if(Loaded)
    FileUnloadItemClick(this);

  if(Server->Active)
    Server->Active = false;

  Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GSvClick(TObject *Sender)
{
  int         Number;
  char        Direction;
  AnsiString  Name;
  TShape      *Shape;
  TImage      *Image;
  TSvetofor   *Sv;

  vector<TGSvetofor*>::const_iterator GSvCur;

  Image = dynamic_cast<TImage*>(Sender);

  Name = Image->Name;
  Name = Name.SubString(6, 3);
  Number = StrToInt(Name);

  for(GSvCur = GSvVec->begin(); GSvCur < GSvVec->end(); GSvCur++)
    if((*GSvCur)->GetSvetofor()->GetId() == Number)
      break;

  Sv = BlockN->GetSvetoforById(Number);
  if(!Sv)
    Sv = BlockC->GetSvetoforById(Number);

  Sv->SetForceOpen(!Sv->GetForceOpen());

/*
  if(Direction == 'C')
    BlockC->GetSvetofor(Number)->SetForceOpen(!BlockC->GetSvetofor(Number)->GetForceOpen());
  else
    BlockN->GetSvetofor(Number)->SetForceOpen(!BlockN->GetSvetofor(Number)->GetForceOpen());
*/
}

void __fastcall TForm1::KickButtonClick(TObject *Sender)
{
  ushort      Num;
  int         Res;
  AnsiString  Str;

  vector<TNTrain*>::iterator  Train;

  Num = StrToInt(TrainGrid->Cells[0][TrainGrid->Selection.Top]);

  Train = FindTrainByNum(Num);

  Str = "Вы действительно хотите удалить поезд " + IntToStr(Num) + "?";
  Res = MessageBox(Form1->Handle, Str.c_str(),
        "Предупреждение", MB_YESNO | MB_ICONQUESTION);

  if(Res == ID_YES)
  {
    if((*Train)->itsThread)
      if((*Train)->itsThread->Connection->Connected())
        (*Train)->itsThread->Connection->Disconnect();

    BlockN->DeleteTrain(Num);
    BlockC->DeleteTrain(Num);

    TrainVec->erase(Train);
  }

/*
  for(Current = TrainVec->begin(); Current < TrainVec->end(); Current++)
  {
    if((*Current)->itsNum == Num)
    {
      TrainVec->erase(Current);
      BlockN->DeleteTrain(Num);
      BlockC->DeleteTrain(Num);

      if((*Current)->itsThread->Connection->Connected())
        (*Current)->itsThread->Connection->Disconnect();
    }
  }
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerDisconnect(TIdPeerThread *AThread)
{
  vector<TNTrain*>::iterator  Train;

  Train = FindTrainByThread(AThread);

  if(Train)
    (*Train)->itsThread = 0;
  /*
  vector<TNTrain*>::iterator  Current;

  for(Current = TrainVec->begin(); Current < TrainVec->end(); Current++)
  {
    if((*Current)->itsThread == AThread)
    {
      TrainVec->erase(Current);
      BlockN->DeleteTrain((*Current)->itsNum);
      BlockC->DeleteTrain((*Current)->itsNum);
    }
  }
  */ 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  int Res;

  Res = MessageBox(Form1->Handle, "Вы действительно хотите выйти?",
    "Предупреждение", MB_YESNO | MB_ICONQUESTION);

  if(Res == ID_YES)
    CanClose = true;
  else
    CanClose = false;  
}
//---------------------------------------------------------------------------

vector<TNTrain*>::iterator TForm1::FindTrainByNum(ushort aNum)
{
  vector<TNTrain*>::iterator  Train;

  for(Train = TrainVec->begin(); Train < TrainVec->end(); Train++)
    if((*Train)->itsNum == aNum)
      return Train;

  return 0;
}


vector<TNTrain*>::iterator TForm1::FindTrainByThread(TIdPeerThread *aThread)
{
  vector<TNTrain*>::iterator Train;

  for(Train = TrainVec->begin(); Train < TrainVec->end(); Train++)
    if((*Train)->itsThread == aThread)
      return Train;

    return 0;
}

void __fastcall TForm1::TimerBgTimer(TObject *Sender)
{
  PultImage->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerTimeTimer(TObject *Sender)
{
  int Hour;
  int Minute;

  Hour = StrToInt(HourEdit->Text);
  Minute = StrToInt(MinuteEdit->Text);

  Minute++;

  if(Minute == 60)
  {
    Minute = 0;
    Hour++;
  }

  if(Hour == 24)
    Hour = 0;

  HourEdit->Text = Hour;
  MinuteEdit->Text = Minute;
}
//---------------------------------------------------------------------------





