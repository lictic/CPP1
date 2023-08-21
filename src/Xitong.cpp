#include "main.h"

int Getnumber()/*��ȡ�ļ��г�Ա����*/
{
    fstream fp;
    string a;
    int num=0;
    fp.open(Filename,ios::in);
    while(getline(fp,a))
    {
        num++;
    }
    fp.close();
    return num;
}

Xitong::Xitong()/*���ù��캯����ȡ�ļ�*/
{
    fstream fp;
    fp.open(Filename,ios::in);
    
    if(!fp.is_open())/*�ļ�������*/
    {
        cout<<"�ļ�������"<<endl;
        this->classpointer = NULL;
        this->fileNULL = true;
        this->number = 0;
        fp.close();
        return;
    }

    char ch;/*�ļ�Ϊ��*/
    fp>>ch;
    if(fp.eof())
    {
        cout<<"�ļ�Ϊ��"<<endl;
        this->classpointer = NULL;
        this->fileNULL = true;
        this->number = 0;
        fp.close();
        return;
    }

    this->fileNULL = false;/*�ļ���������*/
    fp.close();
    this->Start();/*���ļ��е�����д��*/
}

void Xitong::Start()/*���ļ��е�����д��*/
{
    fstream fp;
    string a;
    int b;
    b=Getnumber();
    string c1,c2,c3,c4;
    int num1,num2,num3,num4=0;
    newspace *address = new newspace[b];
    this->number = b;
    fp.open(Filename,ios::in);
    while(getline(fp,a))/*������һ��һ�еĶ�ȡ*/
    {
        newspace worker = NULL;
        istringstream record(a);
        record >> c1 >> c2 >> c3 >> c4 >> num1 >> num2 >> num3;
        worker = new People(c1,c2,c3,c4,num1,num2,num3);
        address[num4++] = worker;
    }
    this->classpointer = address;
}

void Xitong::Add()/*¼��һ���³�Ա*/
{
    int newsize,a;
    newsize = this->number + 1;
    string a1,a2,a3,a4;
    newspace *address = new newspace[newsize];
    if(this->classpointer!=NULL)
    {
        for(int i=0;i<this->number;i++)
        {
            address[i]=this->classpointer[i];
        }
    }
    cout<<"�������û���(���15λ): ";
    cin>>a1;
    cout<<"�������Ա�: ";
    cin>>a2;
    cout<<"�������������(YYYY-MM-DD): ";
    cin>>a3;
    cout<<"����������: ";
    cin>>a4;
    newspace worker = NULL;
    worker = new People(a1,a2,a3,a4,newsize);
    address[newsize-1] = worker ;
    delete[] this->classpointer;/*�ͷ�ԭ�пռ�*/
    this->classpointer = address;/*���Ŀռ�ָ��*/
    this->number = newsize;/*��������*/
    this->fileNULL = false;/*�����ļ��Ƿ�Ϊ��*/
    this->Wirtefile();/*��������*/
    cout<<"��ӳɹ�!"<<endl;
}

void Xitong::Remove()/*ɾ��ָ���û�*/
{
    string a;
    int newsize,b=0;
    newsize = this ->number -1;
    newspace *address  = new newspace[newsize];
    cout<<"������Ҫɾ�����û���: ";
    cin>>a;
    for(int i=0;i<this->number;i++)
    {
        if(this->classpointer[i]->name!=a)
        {
            address[b]=this->classpointer[i];
            b++;
        }
    }
    delete[] this->classpointer;/*�ͷ�ԭ��������*/
    this->classpointer = address;/*д���µ�ַ*/
    this->number = newsize;/*�޸ĳ�Ա����*/
    this->Output1();
    this->Wirtefile();
    cout<<"ɾ���ɹ�!"<<endl;
}

void Xitong::Fix()/*�޸�Ӳ����*/
{
    string a;
    int b;
    cout<<"������Ҫ�޸ĵ��û�����Ҫ�޸ĵ�Ӳ����: ";
    cin>>a>>b; 
    for(int i=0;i<this->number;i++)
    {
        if(this->classpointer[i]->name==a)
        {
            this->classpointer[i]->coin=b;
            this->Output(&this->classpointer[i]);
            this->Wirtefile();
            return ;
        }
    }
}
void Xitong::Sort()/*����*/
{
    for(int i=0;i<this->number;i++)
    {
        for(int j=1;j<this->number;j++)
        {
            newspace worker=NULL;
            if(this->classpointer[j]->coin>=this->classpointer[j-1]->coin)
            {
                if(this->classpointer[j]->coin>this->classpointer[j-1]->coin)/*�Ƚ�Ӳ�Ҵ�С*/
                {
                    
                    worker = this->classpointer[j];
                    this->classpointer[j] = this->classpointer[j-1];
                    this->classpointer[j-1] = worker;
                }
                else
                {
                   if(this->classpointer[j]->age>this->classpointer[j-1]->age)/*�Ƚ������С*/
                   {
                    worker = this->classpointer[j];
                    this->classpointer[j] = this->classpointer[j-1];
                    this->classpointer[j-1] = worker;
                   }
                }
                
            }
        }
    }
    this->Output1();
    this->Wirtefile();
}

void Xitong::Output(newspace *address)/*���һ���û�*/
{
    cout<<"$�û���: "<<(*address)->name<<endl;
    cout<<"�Ա�: "<<(*address)->sex<<endl;
    cout<<"��������: "<<(*address)->birthday<<endl;
    cout<<"����: "<<(*address)->email<<endl;
    cout<<"UID: "<<(*address)->UID<<endl;
    cout<<"Ӳ��: "<<(*address)->coin<<endl;
    cout<<"����: "<<(*address)->age<<endl;
}

void Xitong::Output1()/*��������û�*/
{
    for(int i=0;i<this->number;i++)
    {
        cout<<"$�û���: "<<this->classpointer[i]->name<<endl;
        cout<<"�Ա�: "<<this->classpointer[i]->sex<<endl;
       cout<<"��������: "<<this->classpointer[i]->birthday<<endl;
        cout<<"����: "<<this->classpointer[i]->email<<endl;
        cout<<"UID: "<<this->classpointer[i]->UID<<endl;
        cout<<"Ӳ��: "<<this->classpointer[i]->coin<<endl;
        cout<<"����: "<<this->classpointer[i]->age<<endl;
    }
}

void Xitong::Wirtefile()/*������д���ļ�*/
{
    fstream fp;
    int i=0;
    fp.open(Filename,ios::out);
    for(int i;i<this->number;i++)
    {
        fp<< this->classpointer[i]->name <<" "<< this->classpointer[i]->sex <<" "<< this->classpointer[i]->birthday 
        <<" "<< this->classpointer[i]->email <<" "<< this->classpointer[i]->UID <<" "<< this->classpointer[i]->coin
        <<" "<< this->classpointer[i]->age<<endl;
    }
    fp.close();
}
