//---------------------------------------------------------------------------

#ifndef InsertListH
#define InsertListH
//---------------------------------------------------------------------------
void Mes(const char*source);
void Mes();
void Mesh();
void Mes(const char*source,const char*metka);
int Mes(const char*source,const char*metka, int d);

class Insertion
{
public:
Insertion(char*,char*, int);
int Index;
Insertion *PLink;
char Text [130];
char Name[11];

};

class InsertList
{
public:
InsertList();
~InsertList();
void Clear();
void LoadFromFile(char*);
void SaveToFile(char*);
void Add(char*,char*);
void Delete(int);
char *GetIns(int,char*);
int GetCounter();
void ReIndex();
private:
Insertion *PBegin;
Insertion *PEnd;
int Counter;
};
#endif

