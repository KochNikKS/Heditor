//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ActnList.hpp"
#include "ComCtrls.hpp"
#include "Dialogs.hpp"
#include "ExtCtrls.hpp"
#include "ExtDlgs.hpp"
#include "HTTPApp.hpp"
#include "ImgList.hpp"
#include "Menus.hpp"
#include "OleCtnrs.hpp"
#include "ToolWin.hpp"
#include "Buttons.hpp"
#include "Unit6.h"
#include "Trayicon.h"
#include "trayicon.h"
#include <HTTPProd.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Open1;
        TMenuItem *Close1;
        TMenuItem *Save1;
        TMenuItem *Saveas1;
        TMenuItem *InternetExplorer1;
        TMenuItem *Exit1;
        TMenuItem *Edit1;
        TMenuItem *N20;
        TMenuItem *Selectall1;
        TMenuItem *Copy2;
        TMenuItem *Cut2;
        TMenuItem *N15;
        TMenuItem *N1;
        TMenuItem *Insert1;
        TMenuItem *N21;
        TMenuItem *HTMLtag1;
        TMenuItem *N3;
        TMenuItem *HEADtag1;
        TMenuItem *BODYtag1;
        TMenuItem *N4;
        TMenuItem *TABLE1;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *Paragraph1;
        TMenuItem *Font1;
        TMenuItem *N5;
        TMenuItem *img1;
        TMenuItem *N6;
        TMenuItem *N18;
        TMenuItem *Color1;
        TMenuItem *Color2;
        TMenuItem *N7;
        TMenuItem *N2;
        TMenuItem *N10;
        TMenuItem *Properties;
        TMenuItem *N16;
        TMenuItem *N17;
        TOpenDialog *OpenDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TSaveDialog *SaveDialog1;
        TColorDialog *ColorDialog1;
        TFontDialog *FontDialog1;
        TOpenPictureDialog *OpenPictureDialog1;
        TTimer *Timer1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Copy1;
        TMenuItem *Cut1;
        TMenuItem *Paste1;
        TMenuItem *N11;
        TMenuItem *N19;
        TMenuItem *Selectall2;
        TImageList *ImageList1;
        TFindDialog *FindDialog1;
        TReplaceDialog *ReplaceDialog1;
        TPageProducer *PageProducer1;
        TActionList *ActionList1;
        TOleContainer *OleContainer1;
        TRichEdit *RichEdit1;
        TMemo *Memo2;
        TAction *FINDNEXT;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar2;
        TToolButton *ToolButton17;
        TToolButton *ToolButton18;
        TToolButton *ToolButton19;
        TToolButton *ToolButton20;
        TToolButton *ToolButton21;
        TToolButton *ToolButton22;
        TToolButton *ToolButton23;
        TToolButton *ToolButton25;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TFontDialog *FontDialog2;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *N24;
        TMenuItem *N25;
        TToolButton *ToolButton2;
        TToolButton *ToolButton7;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TComboBox *ComboBox1;
        TPrintDialog *PrintDialog1;
        TMenuItem *N26;
        TRichEdit *RichEdit2;
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TStatusBar *StatusBar1;
        TAction *INS;
        TMenuItem *N27;
        TListBox *ListBox1;
        TMenuItem *HTMLtag2;
        TMenuItem *N28;
        TMenuItem *HEADtag2;
        TMenuItem *BODYtag2;
        TMenuItem *N29;
        TMenuItem *TABLE3;
        TMenuItem *N30;
        TMenuItem *N31;
        TMenuItem *Paragraph3;
        TMenuItem *Font2;
        TMenuItem *font3;
        TMenuItem *N32;
        TMenuItem *N33;
        TMenuItem *img3;
        TMenuItem *N34;
        TMenuItem *N35;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TMenuItem *N36;
        TControlBar *ControlBar1;
        TPanel *Panel2;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TAction *Insert;
        TAction *Close;
        TAction *Delete;
        TAction *Save;
        TAction *Reload;
        TAction *Add;
        TTrayIcon *TrayIcon1;
        TMenuItem *N37;
        TMenuItem *INPUT1;
        TMenuItem *Textarea1;
        TMenuItem *Select1;
        TMenuItem *N38;
        TMenuItem *N39;
        TMenuItem *N40;
        TMenuItem *Select2;
        TMenuItem *Textarea2;
        TMenuItem *Input2;
        TApplicationEvents *ApplicationEvents1;
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall Saveas1Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall Selectall1Click(TObject *Sender);
        void __fastcall Copy2Click(TObject *Sender);
        void __fastcall Cut2Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall HTMLtag1Click(TObject *Sender);
        void __fastcall HEADtag1Click(TObject *Sender);
        void __fastcall BODYtag1Click(TObject *Sender);
        void __fastcall TABLE1Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall Paragraph1Click(TObject *Sender);
        void __fastcall Font1Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall img1Click(TObject *Sender);
        void __fastcall Color2Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall OleContainer1Activate(TObject *Sender);
        void __fastcall ToolButton32Click(TObject *Sender);
        void __fastcall CoolBar1Change(TObject *Sender);
        void __fastcall Color1Click(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall N30Click(TObject *Sender);
        void __fastcall RichEdit1SelectionChange(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall N26Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall RichEdit1Change(TObject *Sender);
        void __fastcall ToolButton10Click(TObject *Sender);
        void __fastcall ToolButton11Click(TObject *Sender);
        void __fastcall INSExecute(TObject *Sender);
        void __fastcall RichEdit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall StatusBar1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall N27Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall ListBox1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Selectall2Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall ToolButton16Click(TObject *Sender);
        void __fastcall InsertExecute(TObject *Sender);
        void __fastcall CloseExecute(TObject *Sender);
        void __fastcall DeleteExecute(TObject *Sender);
        void __fastcall SaveExecute(TObject *Sender);
        void __fastcall ReloadExecute(TObject *Sender);
        void __fastcall AddExecute(TObject *Sender);
        void __fastcall INPUT1Click(TObject *Sender);
        void __fastcall Textarea1Click(TObject *Sender);
        void __fastcall Select1Click(TObject *Sender);
        void __fastcall N37Click(TObject *Sender);
        void __fastcall ToolButton2MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall ApplicationEvents1Message(tagMSG &Msg,
          bool &Handled);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
