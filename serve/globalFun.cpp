//
// Created by huang on 2024/6/25.
//

#pragma once
#include "../headers/globalFile.h"
#include "../headers/Identity.h"
#include "fstream"
#include "string"

using namespace std;

//登陆功能
void LoginIn(string fileName , int type){
    Identity *person = nullptr;

    ifstream ifs;  //文件操作对象
    ifs.open("student.txt" , ios::in);  //以只读的形式打开文件

    //文件不存在
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)  //学生登陆
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    } else if (type == 2)   //教练登陆
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名 : " << endl;
    cin >> name;

    cout << "请输入密码 : " << endl;
    cin >> pwd;

    if (type == 1)
    {
        //学生登陆验证
    }else if (type == 2)
    {
        //教练登录验证
    } else if (type == 3)
    {
        //管理员登录验证
    }

    cout << "登陆失败！" << endl;
    system("pause");
    system("cls");
    return;
}