//
// Created by ����bug������ on 2023/6/4.
//

#include "main.h"

int main()
{
    Xitong p;
    int a=0;
    while(a!=6)
    {
        cout<<"1.����û��˻�"<<endl;
        cout<<"2.��������û��˻���Ϣ"<<endl;
        cout<<"3.ɾ���û����������������Ϣ"<<endl;
        cout<<"4.�����û������޸��˻�Ӳ��,������˻�������Ϣ"<<endl;
        cout<<"5.����Ӳ��������"<<endl;
        cout<<"6.���沢�˳�"<<endl;
        cout<<"������Ҫʵ�ֵĹ���: ";
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