//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "InsertList.h"
#include "stdio.h"
#include "IE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ActnList"
#pragma link "ComCtrls"
#pragma link "Dialogs"
#pragma link "ExtCtrls"
#pragma link "ExtDlgs"
#pragma link "HTTPApp"
#pragma link "ImgList"
#pragma link "Menus"
#pragma link "OleCtnrs"
#pragma link "ToolWin"
#pragma link "Buttons"
#pragma link "Unit6"
#pragma link "Trayicon"
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;
bool modified=false;
char FileName[1000] = "";
TFont *REF = new TFont();
bool ins = true;
InsertList *Lst ;
void showLst();
bool DraggedFile = false;
char bufFName[5000]="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
DragAcceptFiles(Form1->Handle,true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
if (!modified)
{
        if (OpenDialog1->Execute())
        {

        RichEdit1->Visible = false;
        RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
        strcpy(FileName, OpenDialog1->FileName.c_str());
        RichEdit1->Visible = true;
        StatusBar1->Panels->Items[1]->Text = FileName;
        modified = false;
        }
}
if (modified)
{
Form2->Show();
Form1->Enabled = false;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Close1Click(TObject *Sender)
{

if (!modified){RichEdit1->Clear();strcpy(FileName,"");}
else
{
        switch (Application->MessageBox("Сохранить изменения в файл","",MB_YESNO|MB_ICONQUESTION))
        {
        case 6:if(SaveDialog1->Execute())RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
                RichEdit1->Clear();strcpy(FileName,"");break;
        case 7:RichEdit1->Clear();strcpy(FileName,"");break;
        }


}
StatusBar1->Panels->Items[1]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Save1Click(TObject *Sender)
{

if (strlen(FileName)>0)
{
if (SaveDialog1->FilterIndex == 1){RichEdit1->PlainText = true;}
if (SaveDialog1->FilterIndex == 2){RichEdit1->PlainText = false;}
RichEdit1->Lines->SaveToFile(FileName);
//StatusBar1->Panels->Items[1]->Text = FileName;
modified = false;
}
else {TObject *g; Saveas1Click(g);}
RichEdit1->PlainText = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Saveas1Click(TObject *Sender)
{
if (SaveDialog1->Execute())
{
if (SaveDialog1->FilterIndex == 1)RichEdit1->PlainText = true;
if (SaveDialog1->FilterIndex == 2)RichEdit1->PlainText = false;
RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
strcpy(FileName, SaveDialog1->FileName.c_str());
StatusBar1->Panels->Items[1]->Text = FileName;
modified = false;
}
RichEdit1->PlainText = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N20Click(TObject *Sender)
{
RichEdit1->Undo();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Selectall1Click(TObject *Sender)
{
RichEdit1->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Copy2Click(TObject *Sender)
{
RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cut2Click(TObject *Sender)
{
RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
if (RichEdit1->Lines->Text.Length()>0) {Form3->Show();}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N16Click(TObject *Sender)
{
if (FontDialog2->Execute()){RichEdit1->SelAttributes->Assign(FontDialog2->Font);}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N17Click(TObject *Sender)
{
ColorDialog1->Execute();RichEdit1->Color = ColorDialog1->Color;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HTMLtag1Click(TObject *Sender)
{
Memo2->Lines->Add("<HTML>"); Memo2->Lines->Add("</HTML>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HEADtag1Click(TObject *Sender)
{
Memo2->Lines->Add("<HEAD>");
Memo2->Lines->Add("<TITLE>");
Memo2->Lines->Add("</TITLE>");
Memo2->Lines->Add("</HEAD>");
Memo2->SelectAll();
Memo2->CutToClipboard();
RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BODYtag1Click(TObject *Sender)
{
Memo2->Lines->Add("<BODY>");
Memo2->Lines->Add("</BODY>");
Memo2->SelectAll();
Memo2->CutToClipboard();
RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TABLE1Click(TObject *Sender)
{
Memo2->Lines->Add("<TABLE>");
Memo2->Lines->Add("</TABLE>");
Memo2->SelectAll();
Memo2->CutToClipboard();
RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
Memo2->Lines->Add("<TD></TD>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
Memo2->Lines->Add("<TR></TR>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paragraph1Click(TObject *Sender)
{
Memo2->Lines->Add("<P ALIGN=left> </P>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Font1Click(TObject *Sender)
{
Memo2->Lines->Add("<FONT COLOR=\"\" FACE=\"\"> </FONT>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
char bb[1000]="";strcat(bb,"<A HREF=\"");
strcat(bb,InputBox("","Путь","").c_str());strcat(bb,"\"> </A>");
Memo2->Lines->Add(bb);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::img1Click(TObject *Sender)
{
char bb[1000]="";strcat(bb,"<IMG SRC=\"");
strcat(bb,InputBox("","Имя файла","").c_str());strcat(bb,"\">");
Memo2->Lines->Add(bb);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Color2Click(TObject *Sender)
{
if (ColorDialog1->Execute())
{
int color = ColorDialog1->Color;
char *j = "";
itoa (color,j,10 );
Memo2->Lines->Add(j);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
//char path[] = ""; strcpy(path,OpenPictureDialog1->FileName.c_str());
Memo2->Lines->Add(OpenDialog1->FileName);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
//char path[] = ""; strcpy(path,OpenDialog1->FileName.c_str());
Memo2->Lines->Add(OpenDialog1->FileName);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OleContainer1Activate(TObject *Sender)
{
OleContainer1->Tag++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton32Click(TObject *Sender)
{
RichEdit1->PlainText = true;
RichEdit1->Lines->SaveToFile("buffer.htm");
if (OleContainer1->Tag>0)OleContainer1->Close();
OleContainer1->CreateLinkToFile("buffer.htm",false);
OleContainer1->DoVerb(ovPrimary);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CoolBar1Change(TObject *Sender)
{
RichEdit1->Top =  CoolBar1->Top + CoolBar1->Height+1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Color1Click(TObject *Sender)
{
if (FontDialog1->Execute())
{
Memo2->Lines->Add(FontDialog1->Font->Name);
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{
/*RichEdit1->PlainText = true;
RichEdit1->Lines->SaveToFile("buffer.htm");
if (OleContainer1->Tag>0)OleContainer1->Close();
OleContainer1->CreateLinkToFile("buffer.htm",false);
OleContainer1->DoVerb(ovPrimary);
*/
int status = 0;
if (modified)
{
int answ = Application->MessageBox("Следует сохранить изменения в файле.","Предупреждение",MB_ICONWARNING|MB_YESNOCANCEL);
if (answ == 2) status = 0;
if (answ == 6 && strlen(FileName)>0) {status = 1; modified = false;}
if (answ == 6 && strlen(FileName)<1)
{
        if (SaveDialog1->Execute())
                {status = 1;
                 strcpy(FileName, SaveDialog1->FileName.c_str());
                 StatusBar1->Panels->Items[2]->Text = FileName;
                 modified=false;
                }
        else status = 0;
}

if (answ == 7) status = 2;

char l[1000]="";
if (status==1) strcpy(l, FileName);
if (status==2)
{strncpy(l, Application->ExeName.c_str(),strlen(Application->ExeName.c_str())-11);
strcat(l, "buffer.htm");}
if (status==0)return;
RichEdit1->PlainText = true;
RichEdit1->Lines->SaveToFile(l);
WideString *ChUrl = new WideString(l);
Form6->CWB->Navigate(ChUrl->c_bstr());
Form6->Show();
}
else{
WideString *ChUrl = new WideString(FileName);
Form6->CWB->Navigate(ChUrl->c_bstr());
Form6->Show();}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
        if (FontDialog2->Execute())
        {
        RichEdit1->SelAttributes->Name = FontDialog2->Font->Name;
        }
}
//---------------------------------------------------------------------------






void __fastcall TForm1::N30Click(TObject *Sender)
{
RichEdit1->SelAttributes->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit1SelectionChange(TObject *Sender)
{
char h[100]="";itoa(RichEdit1->SelAttributes->Size, h,10);
ComboBox1->Text = h;
FontDialog2->Font->Assign(RichEdit1->SelAttributes);
StatusBar1->Panels->Items[2]->Text = RichEdit1->SelAttributes->Name;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{

RichEdit1->SelAttributes->Size =ComboBox1->Items->Strings[ComboBox1->ItemIndex].ToIntDef(8);
RichEdit1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N24Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
        if (ColorDialog1->Execute())
        {
        RichEdit1->SelAttributes->Color = ColorDialog1->Color;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::N25Click(TObject *Sender)
{
 ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
REF->Assign(FontDialog2->Font);
RichEdit1->Font = REF;
if (ParamCount()>0)
{
RichEdit1->Visible = false;
RichEdit1->Lines->LoadFromFile(ParamStr(ParamCount()).c_str());
strcpy(FileName, ParamStr(ParamCount()).c_str());
StatusBar1->Panels->Items[1]->Text = FileName;
modified = false;
RichEdit1->Visible = true;
}
Lst = new InsertList();
char k[1000]="";
strncpy(k,Application->ExeName.c_str(),strlen(Application->ExeName.c_str())-11);
strcat(k,"Insertions.dat");Lst->LoadFromFile(k);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ToolButton4Click(TObject *Sender)
{
if (PrintDialog1->Execute())
{
RichEdit1->Print("");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N26Click(TObject *Sender)
{
if (PrintDialog1->Execute())
{
        if (poSelection)
        {
        RichEdit2->Lines->Text = RichEdit1->SelText;
        TRect l;l.Left = 100;l.Top = 100;l.Right = 100;l.Bottom = 100;
        RichEdit2->PageRect = l;RichEdit2->Print("Документ HEditor");
        }
        else
        {
        TRect l;l.Left = 100;l.Top = 100;l.Right = 100;l.Bottom = 100;RichEdit1->PageRect = l;
        RichEdit1->Print("Документ HEditor");
        }
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormActivate(TObject *Sender)
{
RichEdit1->SetFocus();
if (ins) StatusBar1->Panels->Items[0]->Text = "Insert";
else StatusBar1->Panels->Items[0]->Text = "Overwrite";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
Form3->Button1->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
modified = true;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::ToolButton10Click(TObject *Sender)
{
Application->Minimize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton11Click(TObject *Sender)
{
TrayIcon1->Minimize();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::INSExecute(TObject *Sender)
{
ins = (ins)?false:true;
if (ins) StatusBar1->Panels->Items[0]->Text = "Insert";
else StatusBar1->Panels->Items[0]->Text = "Overwrite";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RichEdit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (!ins) RichEdit1->SelLength=1;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StatusBar1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
int x1 = StatusBar1->Panels->Items[0]->Width;
int x2 =StatusBar1->Panels->Items[0]->Width +StatusBar1->Panels->Items[1]->Width;
if (X >= x1 && X < x2) StatusBar1->Hint = FileName;
if (X>= x2) StatusBar1->Hint = RichEdit1->SelAttributes->Name;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N27Click(TObject *Sender)
{
Form5->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N10Click(TObject *Sender)
{
if (!ListBox1->Visible){ListBox1->Clear();showLst();ListBox1->Show();
Panel2->Visible = true;
ToolBar1->Enabled = false;ToolBar2->Enabled = false;//ToolBar3->Enabled = false;
PopupMenu1->AutoPopup = false;
File1->Enabled = false;Edit1->Enabled = false;Properties->Enabled = false;
Insert1->Enabled = false;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ListBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//if (Button==mbRight) {ListBox1->Clear();ListBox1->Hide(); }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Selectall2Click(TObject *Sender)
{
RichEdit1->SelectAll();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N6Click(TObject *Sender)
{
Memo2->Lines->Add("<FRAMESET>\n<FRAME SRC="">\n</FRAMESET>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button5Click(TObject *Sender)
{

Lst = new InsertList();
Lst->LoadFromFile("Insertions.dat");
int i  =0;
char *j="";
ListBox1->Clear();
while(i < Lst->GetCounter())
{
Lst->GetIns(i,j);
ListBox1->Items->Add(j);
i++;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ToolButton16Click(TObject *Sender)
{
Lst->LoadFromFile("Insertions.dat");
}
//---------------------------------------------------------------------------


void showLst()
{int i = 0;char t[11]="";
     while (i < Lst->GetCounter()){Lst->GetIns(i,t);Form1->ListBox1->Items->Add(t);i++;}
}

void __fastcall TForm1::InsertExecute(TObject *Sender)
{
char *k="";
Memo2->Lines->Add(Lst->GetIns(ListBox1->ItemIndex,k));
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
//ListBox1->Clear();ListBox1->Hide();Button1->Hide();Button2->Hide();Button3->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CloseExecute(TObject *Sender)
{
ListBox1->Clear();
Panel2->Visible = false;
ListBox1->Hide();
ToolBar1->Enabled = true;
ToolBar2->Enabled = true;
//ToolBar3->Enabled = true;
PopupMenu1->AutoPopup = true;
File1->Enabled = true;
Edit1->Enabled = true;
Properties->Enabled = true;
Insert1->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteExecute(TObject *Sender)
{
if (ListBox1->ItemIndex>-1)
{
Lst->Delete(ListBox1->ItemIndex);
ListBox1->Items->Delete(ListBox1->ItemIndex);
}        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveExecute(TObject *Sender)
{
Lst->SaveToFile("Insertions.dat");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReloadExecute(TObject *Sender)
{
Lst->LoadFromFile("Insertions.dat");
ListBox1->Clear();
int i = 0;char t[11]="";
while (i < Lst->GetCounter()){Lst->GetIns(i,t);ListBox1->Items->Add(t);i++;}
ListBox1->Show();Panel2->Visible = true;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::AddExecute(TObject *Sender)
{
Form5->Show();
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::INPUT1Click(TObject *Sender)
{
Memo2->Lines->Add("<INPUT TYPE=\"\" NAME=\"\" MAXLENGTH=\"\" SIZE=\"\" CHECKED=\"\" SRC=\"\">");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Textarea1Click(TObject *Sender)
{
Memo2->Lines->Add("<TEXTAREA NAME=\"\" ROWS=\"\" COLS=\"\">\"\"</TEXTAREA>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Select1Click(TObject *Sender)
{
Memo2->Lines->Add("<SELECT NAME=\"\">\n<OPTION>\n</SELECT>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N37Click(TObject *Sender)
{
Memo2->Lines->Add("<FORM METHOD=\"\" ACTION=\"\">\n</FORM>");
Memo2->SelectAll();Memo2->CutToClipboard();RichEdit1->PasteFromClipboard();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
ToolButton2->Hint=FontDialog2->Font->Name;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Message(tagMSG &Msg,
      bool &Handled)
{
if (Msg.message==WM_DROPFILES)
{
          char* d="";
          UINT G = 1000;
          HDROP hDrop;
          LPPOINT lppt;
          DragQueryFile((HANDLE)Msg.wParam,0,d,G);

          if (!modified)
          {
          RichEdit1->Visible = false;
          RichEdit1->Lines->LoadFromFile(d);
          strcpy(FileName, d);
          RichEdit1->Visible = true;
          StatusBar1->Panels->Items[1]->Text = FileName;
          modified = false;
          }
          else
          {
          DraggedFile = true;
          strcpy(bufFName, d);
          Form1->Enabled= false;
          Form2->Show();
          }



}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
if (modified)
{
char *u = "Вы хотите сохранить изменения?";
char *y = "HEditor";
int t = Application->MessageBox(u,y,MB_YESNOCANCEL|MB_ICONQUESTION);
if (t==IDYES) {ToolButton18->Click();Action = caFree;}
if (t==IDNO)  {Application->Terminate();Action = caFree;}
if (t==IDCANCEL) Action = caNone;
} else Application->Terminate();
}
//---------------------------------------------------------------------------



