//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "InsertList.h"
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Buttons"
#pragma link "ExtCtrls"
#pragma link "Graphics"
#pragma resource "*.dfm"

TForm5 *Form5;
extern InsertList *Lst;
extern void showLst();
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::BitBtn2Click(TObject *Sender)
{
Form5->Hide();        
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormHide(TObject *Sender)
{
Form1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormShow(TObject *Sender)
{
Form1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::BitBtn1Click(TObject *Sender)
{
AnsiString name = InputBox("Введите название вставки","Не более 10 букв","Unnamed");
while (name.Length()<1)
{name = InputBox("Введите название вставки","Не более 10 букв","Unnamed");}
char h[1000]=""; strcpy(h,"\n");strcat(h,Memo1->Lines->Text.c_str());strcat(h,"\n");
Lst->Add(name.c_str(),h);
Lst->SaveToFile("Insertions.dat");
Form5->Hide();
Form1->ListBox1->Clear();
showLst();
Form1->ListBox1->Show();
Form1->Panel2->Show();
}
//---------------------------------------------------------------------------
