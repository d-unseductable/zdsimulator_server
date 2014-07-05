//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPServer.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <IdIPWatch.hpp>

#include <vector.h>

#include "GSvetofor.h"
#include "GBlock.h"
#include "NetStruct.h"

struct TNTrain
{
  ushort        itsNum;
  TIdPeerThread *itsThread;
};

struct TStation
{
  char      itsName[30];
  ushort    itsStartTrack;
  ushort    itsEndTrack;
  ushort    itsECTrack;
  TDateTime itsStoppedTime;
  TDateTime itsStartedTime;
  TDateTime itsMovedTime;
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TStringGrid *SvetoforGrid;
  TStringGrid *TrainGrid;
  TTimer *Timer1;
  TIdTCPServer *Server;
  TMainMenu *MainMenu1;
  TMenuItem *FileMenu;
  TMenuItem *FileLoadItem;
  TMenuItem *FileUnloadItem;
  TMenuItem *N1;
  TMenuItem *FileExitItem;
  TMenuItem *NetMenu;
  TMenuItem *NetActivateItem;
  TMenuItem *NetDeactivateItem;
  TStatusBar *StatusBar;
  TLabel *Label1;
  TEdit *PortEdit;
  TIdIPWatch *IPWatch;
  TLabel *Label2;
  TEdit *HourEdit;
  TImage *PultImage;
  TButton *KickButton;
  TPaintBox *PaintBox;
  TTimer *TimerBg;
  TEdit *MinuteEdit;
  TLabel *Label3;
  TTimer *TimerTime;
  TTimer *TimerTrain;
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall SvShapeMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall GSvClick(TObject *Sender);
  void __fastcall ServerExecute(TIdPeerThread *AThread);
  void __fastcall FileLoadItemClick(TObject *Sender);
  void __fastcall FileUnloadItemClick(TObject *Sender);
  void __fastcall NetActivateItemClick(TObject *Sender);
  void __fastcall NetDeactivateItemClick(TObject *Sender);
  void __fastcall FileExitItemClick(TObject *Sender);
  void __fastcall KickButtonClick(TObject *Sender);
  void __fastcall ServerDisconnect(TIdPeerThread *AThread);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall TimerBgTimer(TObject *Sender);
  void __fastcall TimerTimeTimer(TObject *Sender);

private:	// User declarations
  void  ReadSvetofors();
  void  ReadTrains();
  void  ReadBlocks();
  
  void  ShowSvetofors();
  void  ShowTrains();
  void  ShowBlocks();

  void FindVisibles();

  vector<TNTrain*>::iterator  FindTrainByNum(ushort aNum);
  vector<TNTrain*>::iterator  FindTrainByThread(TIdPeerThread *aThread);

  int         NumSpacers;
  bool        Loaded;
  AnsiString  RouteName;

/*
  TShape  **ShapesC;
  TLabel  **LabelsC;
  TShape  **ShapesN;
  TLabel  **LabelsN;
  TBevel  **SpacerBevs;
*/
  vector<TShape*>     *ShapesVec;

  vector<TGSvetofor*> *GSvVec;
  vector<TGBlock*>    *GBlockVec;
  vector<TNTrain*>    *TrainVec;
  vector<TVisibles*>  *VisibleVec;
  vector<TStation*>   *Stations;
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 