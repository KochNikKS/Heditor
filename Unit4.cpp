//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::CheckBox1Click(TObject *Sender)
{
CheckBox2->Checked = false;
CheckBox3->Checked = false;
CheckBox4->Checked = false;
CheckBox5->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
TFontStyles g;
if (CheckBox2->Checked) g<<fsBold;if (CheckBox3->Checked) g<<fsItalic;
if (CheckBox4->Checked) g<<fsUnderline;if (CheckBox5->Checked) g<<fsStrikeOut;
Form1->RichEdit1->SelAttributes->Style = g;
Form4->Hide();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormHide(TObject *Sender)
{
Form1->Enabled = true;       
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
Form1->Enabled = false;        
}
//---------------------------------------------------------------------------
