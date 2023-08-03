#include "main.h"

int People::Getage()
{
    int sum=0,a;
     for(int i=0;i<=3;i++)
    {
        switch (this->birthday[i])
        {
        case '1':sum=sum*10+1;
            break;
        case '2':sum=sum*10+2;
            break;
        case '3':sum=sum*10+3;
            break;
        case '4':sum=sum*10+4;
            break;
        case '5':sum=sum*10+5;
            break;
        case '6':sum=sum*10+6;
            break;
        case '7':sum=sum*10+7;
            break;
        case '8':sum=sum*10+8;
            break;
        case '9':sum=sum*10+9;
            break;
        case '0':sum=sum*10+0;
            break;
        default:
            break;
        }
    }
    a=2023-sum;
    return a;
}
People:: People(string gname,string gsex,string gbirthday,string gemail,int gUID,int gcoin,int gage)
{
    this->name = gname;
    this->sex = gsex;
    this->birthday = gbirthday;
    this->email = gemail;
    if(gcoin==100)
    {
        this->coin = 100;
    }
    else
    {
        this->coin = gcoin;
    }
    this->UID = gUID;
    if(gage==0)
    {
        this->age = Getage();
    }
    else
    {
        this->age = gage;
    }
}
void People::show()
{
    cout<<"$用户名: "<<this->name<<endl;
    cout<<"性别: "<<this->sex<<endl;
    cout<<"出生日期: "<<this->birthday<<endl;
    cout<<"邮箱:"<<this->email<<endl;
    cout<<"UID: "<<this->UID<<endl;
    cout<<"硬币: "<<this->coin<<endl;
    cout<<"年龄: "<<this->age<<endl;
}