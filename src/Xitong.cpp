#include "main.h"

int Getnumber()/*获取文件中成员个数*/
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

Xitong::Xitong()/*利用构造函数读取文件*/
{
    fstream fp;
    fp.open(Filename,ios::in);
    
    if(!fp.is_open())/*文件不存在*/
    {
        cout<<"文件不存在"<<endl;
        this->classpointer = NULL;
        this->fileNULL = true;
        this->number = 0;
        fp.close();
        return;
    }

    char ch;/*文件为空*/
    fp>>ch;
    if(fp.eof())
    {
        cout<<"文件为空"<<endl;
        this->classpointer = NULL;
        this->fileNULL = true;
        this->number = 0;
        fp.close();
        return;
    }

    this->fileNULL = false;/*文件存在数据*/
    fp.close();
    this->Start();/*将文件中的数据写入*/
}

void Xitong::Start()/*将文件中的数据写入*/
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
    while(getline(fp,a))/*将数据一行一行的读取*/
    {
        newspace worker = NULL;
        istringstream record(a);
        record >> c1 >> c2 >> c3 >> c4 >> num1 >> num2 >> num3;
        worker = new People(c1,c2,c3,c4,num1,num2,num3);
        address[num4++] = worker;
    }
    this->classpointer = address;
}

void Xitong::Add()/*录入一个新成员*/
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
    cout<<"请输入用户名(最多15位): ";
    cin>>a1;
    cout<<"请输入性别: ";
    cin>>a2;
    cout<<"请输入出生年月(YYYY-MM-DD): ";
    cin>>a3;
    cout<<"请输入邮箱: ";
    cin>>a4;
    newspace worker = NULL;
    worker = new People(a1,a2,a3,a4,newsize);
    address[newsize-1] = worker ;
    delete[] this->classpointer;/*释放原有空间*/
    this->classpointer = address;/*更改空间指向*/
    this->number = newsize;/*更改人数*/
    this->fileNULL = false;/*更改文件是否为空*/
    this->Wirtefile();/*保存数据*/
    cout<<"添加成功!"<<endl;
}

void Xitong::Remove()/*删除指定用户*/
{
    string a;
    int newsize,b=0;
    newsize = this ->number -1;
    newspace *address  = new newspace[newsize];
    cout<<"请输入要删除的用户名: ";
    cin>>a;
    for(int i=0;i<this->number;i++)
    {
        if(this->classpointer[i]->name!=a)
        {
            address[b]=this->classpointer[i];
            b++;
        }
    }
    delete[] this->classpointer;/*释放原堆区数据*/
    this->classpointer = address;/*写入新地址*/
    this->number = newsize;/*修改成员个数*/
    this->Output1();
    this->Wirtefile();
    cout<<"删除成功!"<<endl;
}

void Xitong::Fix()/*修改硬币数*/
{
    string a;
    int b;
    cout<<"请输入要修改的用户名和要修改的硬币数: ";
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
void Xitong::Sort()/*排序*/
{
    for(int i=0;i<this->number;i++)
    {
        for(int j=1;j<this->number;j++)
        {
            newspace worker=NULL;
            if(this->classpointer[j]->coin>=this->classpointer[j-1]->coin)
            {
                if(this->classpointer[j]->coin>this->classpointer[j-1]->coin)/*比较硬币大小*/
                {
                    
                    worker = this->classpointer[j];
                    this->classpointer[j] = this->classpointer[j-1];
                    this->classpointer[j-1] = worker;
                }
                else
                {
                   if(this->classpointer[j]->age>this->classpointer[j-1]->age)/*比较年龄大小*/
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

void Xitong::Output(newspace *address)/*输出一个用户*/
{
    cout<<"$用户名: "<<(*address)->name<<endl;
    cout<<"性别: "<<(*address)->sex<<endl;
    cout<<"出生日期: "<<(*address)->birthday<<endl;
    cout<<"邮箱: "<<(*address)->email<<endl;
    cout<<"UID: "<<(*address)->UID<<endl;
    cout<<"硬币: "<<(*address)->coin<<endl;
    cout<<"年龄: "<<(*address)->age<<endl;
}

void Xitong::Output1()/*输出所有用户*/
{
    for(int i=0;i<this->number;i++)
    {
        cout<<"$用户名: "<<this->classpointer[i]->name<<endl;
        cout<<"性别: "<<this->classpointer[i]->sex<<endl;
       cout<<"出生日期: "<<this->classpointer[i]->birthday<<endl;
        cout<<"邮箱: "<<this->classpointer[i]->email<<endl;
        cout<<"UID: "<<this->classpointer[i]->UID<<endl;
        cout<<"硬币: "<<this->classpointer[i]->coin<<endl;
        cout<<"年龄: "<<this->classpointer[i]->age<<endl;
    }
}

void Xitong::Wirtefile()/*将数据写入文件*/
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
