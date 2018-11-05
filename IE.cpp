//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IE.h"
#include "Unit1.h"
#include "stdio.h"
#include "Dir.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "OleCtrls"
#pragma link "SHDocVw_OCX"
#pragma link "ComCtrls"
#pragma link "ToolWin"
#pragma link "Buttons"
#pragma link "ImgList"
#pragma link "ExtCtrls"
#pragma link "Graphics"
#pragma link "OleServer"
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::SpeedButton1Click(TObject *Sender)
{
CWB->GoBack();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton2Click(TObject *Sender)
{
CWB->GoForward();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton4Click(TObject *Sender)
{
CWB->Stop();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton3Click(TObject *Sender)
{
CWB->Refresh();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton6Click(TObject *Sender)
{
CWB->GoHome();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton5Click(TObject *Sender)
{
CWB->GoSearch();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton7Click(TObject *Sender)
{
Form6->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormShow(TObject *Sender)
{
Form1->Enabled = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormHide(TObject *Sender)
{
Form1->Enabled = true;
struct ffblk ffblk;
if (findfirst("buffer.htm",&ffblk,0)) remove("buffer.htm");
}
//---------------------------------------------------------------------------






