//
// Created by 神奇bug在哪里 on 2023/6/4.
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
    virtual void show() = 0;/*显示个人信息*/
    virtual int Getage() = 0;/*获取员工年龄*/
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
    People(string gname,string gsex,string gbirthday,string gemail,int gUID,int gcoin=100,int gage=0);/*构造函数*/
    virtual void show();/*显示个人信息*/
    virtual int Getage();/*获取员工年龄*/
};

class Xitong
{
public:
    Xitong();
    void Start();/*初始化用户信息,将文件中的信息写入*/
    void Add();/*添加用户*/
    void Output(newspace *address);/*输出成员*/
    void Output1();/*输出全部成员*/
    void Remove();/*删除用户*/
    void Fix();/*修改硬币数*/
    void Sort();/*排序用户*/
    void Wirtefile();/*将数据写入文件*/
    void Exitsystem();/*退出系统*/
public:
    newspace *classpointer;
    int number;
    bool fileNULL;/*判断文件是否为空*/
};
#endif //CPP_PROJECT_1_MAIN_H
