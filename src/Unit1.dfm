object Form1: TForm1
  Left = 230
  Top = 27
  Width = 1089
  Height = 700
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #1055#1091#1083#1100#1090' '#1044#1053#1062
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 920
    Top = 40
    Width = 28
    Height = 13
    Caption = #1055#1086#1088#1090':'
  end
  object Label2: TLabel
    Left = 920
    Top = 16
    Width = 36
    Height = 13
    Caption = #1042#1088#1077#1084#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object PultImage: TImage
    Left = 0
    Top = 0
    Width = 913
    Height = 617
  end
  object PaintBox: TPaintBox
    Left = 0
    Top = 0
    Width = 913
    Height = 617
  end
  object Label3: TLabel
    Left = 986
    Top = 13
    Width = 3
    Height = 13
    Caption = ':'
  end
  object SvetoforGrid: TStringGrid
    Left = 40
    Top = 24
    Width = 273
    Height = 305
    ColCount = 4
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 0
    Visible = False
  end
  object TrainGrid: TStringGrid
    Left = 920
    Top = 64
    Width = 145
    Height = 417
    ColCount = 3
    DefaultColWidth = 45
    DefaultRowHeight = 22
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 623
    Width = 1073
    Height = 19
    Panels = <
      item
        Text = #1053#1077#1090' '#1089#1086#1077#1076#1080#1085#1077#1085#1080#1103
        Width = 100
      end
      item
        Width = 100
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object PortEdit: TEdit
    Left = 960
    Top = 32
    Width = 105
    Height = 21
    TabOrder = 3
    Text = '7691'
  end
  object HourEdit: TEdit
    Left = 960
    Top = 8
    Width = 25
    Height = 21
    TabOrder = 4
    Text = '16'
  end
  object KickButton: TButton
    Left = 920
    Top = 496
    Width = 75
    Height = 25
    Caption = #1054#1090#1082#1083#1102#1095#1080#1090#1100
    TabOrder = 5
    OnClick = KickButtonClick
  end
  object MinuteEdit: TEdit
    Left = 992
    Top = 8
    Width = 25
    Height = 21
    TabOrder = 6
    Text = '30'
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 600
    Top = 40
  end
  object Server: TIdTCPServer
    Bindings = <>
    DefaultPort = 0
    OnExecute = ServerExecute
    OnDisconnect = ServerDisconnect
    Left = 600
    Top = 72
  end
  object MainMenu1: TMainMenu
    Left = 600
    Top = 8
    object FileMenu: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object FileLoadItem: TMenuItem
        Caption = '&'#1047#1072#1075#1088#1091#1079#1080#1090#1100
        ShortCut = 16463
        OnClick = FileLoadItemClick
      end
      object FileUnloadItem: TMenuItem
        Caption = '&'#1042#1099#1075#1088#1091#1079#1080#1090#1100
        Enabled = False
        ShortCut = 16469
        OnClick = FileUnloadItemClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object FileExitItem: TMenuItem
        Caption = #1042'&'#1099#1093#1086#1076
        ShortCut = 16505
        OnClick = FileExitItemClick
      end
    end
    object NetMenu: TMenuItem
      Caption = '&'#1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077
      Enabled = False
      object NetActivateItem: TMenuItem
        Caption = '&'#1040#1082#1090#1080#1074#1080#1088#1086#1074#1072#1090#1100
        ShortCut = 16449
        OnClick = NetActivateItemClick
      end
      object NetDeactivateItem: TMenuItem
        Caption = '&'#1044#1077#1072#1082#1090#1080#1074#1080#1088#1086#1074#1072#1090#1100
        Enabled = False
        ShortCut = 16452
        OnClick = NetDeactivateItemClick
      end
    end
  end
  object IPWatch: TIdIPWatch
    HistoryEnabled = False
    HistoryFilename = 'iphist.dat'
    Left = 600
    Top = 104
  end
  object TimerBg: TTimer
    Enabled = False
    Interval = 30000
    OnTimer = TimerBgTimer
    Left = 632
    Top = 40
  end
  object TimerTime: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = TimerTimeTimer
    Left = 664
    Top = 40
  end
  object TimerTrain: TTimer
    Enabled = False
    Interval = 5000
    Left = 800
    Top = 40
  end
end
