//
// Created by ����bug������ on 2023/6/4.
//

#ifndef CPP_PROJECT_1_MAIN_H
#define CPP_PROJECT_1_MAIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#define Filename "C:\\shiyan3\\CPP1\\src\\wenjian.txt"
using namespace std;


class Biyou
{
public:
    virtual void show() = 0;/*��ʾ������Ϣ*/
    virtual int Getage() = 0;/*��ȡԱ������*/
    string name;
    string sex;
    string birthday;
    string email;
    int UID;
    int coin;
    int age;
};
typedef Biyou * newspace;

class People:public Biyou
{
public:
    People(string gname,string gsex,string gbirthday,string gemail,int gUID,int gcoin=100,int gage=0);/*���캯��*/
    virtual void show();/*��ʾ������Ϣ*/
    virtual int Getage();/*��ȡԱ������*/
};

class Xitong
{
public:
    Xitong();
    void Start();/*��ʼ���û���Ϣ,���ļ��е���Ϣд��*/
    void Add();/*����û�*/
    void Output(newspace *address);/*�����Ա*/
    void Output1();/*���ȫ����Ա*/
    void Remove();/*ɾ���û�*/
    void Fix();/*�޸�Ӳ����*/
    void Sort();/*�����û�*/
    void Wirtefile();/*������д���ļ�*/
    void Exitsystem();/*�˳�ϵͳ*/
public:
    newspace *classpointer;
    int number;
    bool fileNULL;/*�ж��ļ��Ƿ�Ϊ��*/
};
#endif //CPP_PROJECT_1_MAIN_H
