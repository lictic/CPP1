//
// Created by 神奇bug在哪里 on 2023/6/4.
//

#include "main.h"

int main()
{
    Xitong p;
    int a=0;
    while(a!=6)
    {
        cout<<"1.添加用户账户"<<endl;
        cout<<"2.输出所有用户账户信息"<<endl;
        cout<<"3.删除用户并输出余下所有信息"<<endl;
        cout<<"4.输入用户名并修改账户硬币,输出该账户信息"<<endl;
        cout<<"5.按照硬币数排序"<<endl;
        cout<<"6.保存并退出"<<endl;
        cout<<"请输入要实现的功能: ";
        cin>>a;
        if(a==1)
        {
            p.Add();
        }
        else if(a==2)
        {
            p.Output1();
        }
        else if(a==3)
        {
            p.Remove();
            
        }
        else if(a==4)
        {
            p.Fix();
        }
        else if(a==5)
        {
            p.Sort();
        }
        else if(a==6)
        {
            return 0;
        }
    }
    return 0;
}