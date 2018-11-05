//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InsertList.h"
#include  <fstream.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
void Mes(const char*source)
{Application->MessageBox(source,"",0);}
void Mes()
{Application->MessageBox("","",0);}
void Mesh()
{Application->MessageBox("Hello!","Marker",0);}

void Mes(const char*source,const char*metka)
{Application->MessageBox(source,metka,0);}

int Mes(const char*source,const char*metka, int d)
{return Application->MessageBox(source,metka,d);}


Insertion::Insertion(char *InitName, char *InitText, int i){strcpy(Text,InitText);
Index = i;PLink = 0;strcpy(Name,InitName);}
//***************************************************************************
InsertList::InsertList(){Counter = 0;PBegin = 0; PEnd = 0;}

InsertList::~InsertList(){delete PBegin;delete PEnd;}

void InsertList::Clear(){Counter = 0;PBegin = 0; PEnd = 0;}

void InsertList::Add(char*n, char *src)
{
       if (Counter==0)
       {
       Insertion *PBuf = new Insertion(n,src, 0);
        PBegin = PBuf;PEnd = PBuf; Counter=1; }
        else{Insertion *PBuf = new Insertion(n,src, Counter);
        PEnd->PLink = PBuf; PEnd = PBuf; Counter++;}
}

void InsertList::Delete(int ind)
{
if (ind==0){Insertion*PCur=PBegin;PBegin = PBegin->PLink; delete PCur;}

if (ind>0 && ind < Counter)
{
Insertion*PCur=PBegin;
while (PCur->Index<ind-1) {PCur = PCur->PLink;}
Insertion* PDelete = PCur->PLink;
PCur->PLink = PDelete->PLink;delete PDelete;
}

Counter-- ;
ReIndex();

}

void InsertList::ReIndex()
{
int i = 0;
Insertion*PCur = PBegin;
while (i < Counter){PCur->Index = i;PCur = PCur->PLink;i++;}

}


int InsertList::GetCounter(){return Counter;}

char *InsertList::GetIns(int I, char*name)
{
int pos = 0;  Insertion*PMove = PBegin;
        while (pos < Counter)
        {
        if (PMove->Index==I){strcpy(name,PMove->Name);return PMove->Text;}
        PMove = PMove->PLink;
        pos++;
        }
        name = 0;
        return 0;

}
void InsertList::LoadFromFile(char*FlName)
{
Counter = 0;
ifstream FName(FlName);
if (!FName)
{Application->MessageBox("Файл не найден","ERROR",MB_OK|MB_ICONERROR);
return;}
char buffer[1000]="";
char buf[1000]="";
char constr [1000]="";
char nm [11]="";

while (!FName.eof())
{
strcpy(buf,"");
        while (strcmp(buf,"[end]")!=0 && !FName.eof()){
        FName.getline(buf,1000);
        if (strcmp(buf,"[end]")!=0){strcat (buffer,buf);if (strlen(buffer)>0)strcat(buffer,"\n");}
        }

        if (strlen(buffer)>14)
        {
        char str1[1000] ="";strcpy(str1,strstr(buffer,"|"));  strcpy(nm,strtok(str1,"|"));
        char str2[1000] ="";strcpy(str2,strstr(buffer,"]"));  strcpy(constr, strtok(str2,"["));
        char *j = constr; j++; strcpy(constr, j);Add(nm, constr);
        } strcpy(buffer,"");
}
}

void InsertList::SaveToFile(char* nme)
{
ofstream fname(nme);
int i = 0;
char*nm="";
char body[1000]="";
//strncpy(body, body, strlen(body)-2);
//body[strlen(body)]='\0';
char record[1000]="";
char begin[]="[begin |";
char endbeg[]="|]";
char end[] = "[end]";
        while (i < Counter)
        {
        strcpy(body,GetIns(i,nm));
        fname <<endl<<begin<<nm<<endbeg<<body<<end;
        strcpy(record,"");
        i++;
        }
}
