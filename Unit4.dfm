object Form4: TForm4
  Left = 213
  Top = 108
  BorderIcons = []
  BorderStyle = bsDialog
  ClientHeight = 162
  ClientWidth = 130
  Color = 12615680
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Scaled = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 129
    Height = 137
    Caption = ' Стиль '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object CheckBox1: TCheckBox
      Left = 4
      Top = 16
      Width = 121
      Height = 17
      Caption = 'Норма'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object CheckBox2: TCheckBox
      Left = 4
      Top = 40
      Width = 97
      Height = 17
      Caption = 'Жирный текст'
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 4
      Top = 64
      Width = 97
      Height = 17
      Caption = 'Косой текст'
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 4
      Top = 88
      Width = 121
      Height = 17
      Caption = 'Подчеркнутый '
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 4
      Top = 112
      Width = 97
      Height = 17
      Caption = 'Зачеркнутый '
      TabOrder = 4
    end
  end
  object Button1: TButton
    Left = 0
    Top = 140
    Width = 129
    Height = 21
    Caption = 'Ok'
    TabOrder = 1
    OnClick = Button1Click
  end
end
