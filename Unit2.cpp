//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm2 *Form2;
extern bool modified;
extern char FileName[];
extern char bufFName[];
extern bool DraggedFile;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Action = caNone;        
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
Form2->Hide();
Form1->Enabled = true;

if (!DraggedFile)
{
 if (Form1->OpenDialog1->Execute())
        {

        Form1->RichEdit1->Visible = false;
        Form1->RichEdit1->Lines->Clear();
        Form1->RichEdit1->Lines->LoadFromFile(Form1->OpenDialog1->FileName);
        strcpy(FileName, Form1->OpenDialog1->FileName.c_str());
        Form1->RichEdit1->Visible = true;
        Form1->StatusBar1->Panels->Items[1]->Text = FileName;
        modified = false;
        }
 }
else
{
          Form2->Hide();
          Form1->Enabled = true;
          Form1->RichEdit1->Visible = false;
          Form1->RichEdit1->Lines->LoadFromFile(bufFName);
          strcpy(FileName, bufFName);
          Form1->RichEdit1->Visible = true;
          Form1->StatusBar1->Panels->Items[1]->Text = FileName;
          modified = false;
}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{
Form2->Hide();
Form1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{
Form1->Enabled = true;
       if (!DraggedFile)
       {
        if (Form1->OpenDialog1->Execute())
        {
        char j[5000]="";
        strcpy (j, Application->ExeName.c_str());
        strcat(j, " ");
        strcat(j, Form1->OpenDialog1->FileName.c_str());
        WinExec(j,1);
        }
       }
       if (DraggedFile)
       {
        /*
        char j[5000]="";
        char *uu = strtok (bufFName,"\\");
        char *buf ="";
        while (uu!=NULL)
        {
        buf = uu;
        uu = strtok(NULL,"\\");
        }

        strcpy(bufFName,buf);
//        ShowMessage(bufFName);
        strcpy (j, Application->ExeName.c_str());
        strcat(j, " ");
        strcat(j, bufFName);
        ShowMessage(j);*/
        WinExec(bufFName,1);


       }
        Form2->Hide();


}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
Form1->ToolButton18->Click();
if (!DraggedFile)
{
Form2->Hide();
Form1->Enabled = true;

        if (Form1->OpenDialog1->Execute())
        {
        Form1->RichEdit1->Visible = false;
        Form1->RichEdit1->Lines->Clear();
        Form1->RichEdit1->Lines->LoadFromFile(Form1->OpenDialog1->FileName);
        strcpy(FileName, Form1->OpenDialog1->FileName.c_str());
        Form1->RichEdit1->Visible = true;
        Form1->StatusBar1->Panels->Items[1]->Text = FileName;
        modified = false;
        }



}
else
{
          Form2->Hide();
          Form1->Enabled = true;
          Form1->RichEdit1->Visible = false;
          Form1->RichEdit1->Lines->LoadFromFile(bufFName);
          strcpy(FileName, bufFName);
          Form1->RichEdit1->Visible = true;
          Form1->StatusBar1->Panels->Items[1]->Text = FileName;
          modified = false;
}


}
//---------------------------------------------------------------------------

