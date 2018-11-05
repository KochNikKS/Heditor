object Form3: TForm3
  Left = 508
  Top = 52
  BorderStyle = bsSingle
  Caption = 'Поиск'
  ClientHeight = 96
  ClientWidth = 260
  Color = 12615680
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clAqua
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 4
    Width = 70
    Height = 13
    Caption = 'Искать слово'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 36
    Top = 24
    Width = 38
    Height = 13
    Caption = 'замена'
  end
  object Edit1: TEdit
    Left = 76
    Top = 0
    Width = 181
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MaxLength = 100
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 76
    Top = 24
    Width = 181
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MaxLength = 100
    ParentFont = False
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 4
    Top = 80
    Width = 73
    Height = 17
    Caption = 'Заменить'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 204
    Top = 48
    Width = 57
    Height = 25
    Caption = 'Найти'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 204
    Top = 72
    Width = 57
    Height = 25
    Caption = 'Отмена'
    TabOrder = 4
    OnClick = Button2Click
  end
  object RadioButton2: TRadioButton
    Left = 4
    Top = 64
    Width = 189
    Height = 17
    Caption = 'От текущей позиции курсора'
    TabOrder = 5
  end
  object RadioButton1: TRadioButton
    Left = 4
    Top = 48
    Width = 189
    Height = 17
    Caption = 'Весь текст'
    Checked = True
    TabOrder = 6
    TabStop = True
  end
end
