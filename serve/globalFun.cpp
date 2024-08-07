//
// Created by huang on 2024/6/25.
//

#pragma once
#include "../headers/globalFile.h"
#include "../headers/Identity.h"
#include "student.cpp"
#include "coach.cpp"
#include "manager.cpp"
#include "fstream"
#include "string"

using namespace std;

//管理员菜单
void mangerMenu(Identity * &manager){
    while (true){
        //管理员菜单
        manager->operMenu();

        Manager *man = (Manager *)manager;
        int select = 0;
        cin >> select;
        if (select == 1){   //添加账号
            cout << "添加账号" << endl;
            man->addPerson();
        } else if (select == 2){  //查看账号
            cout << "查看账号" << endl;
            man->showPerson();
        } else if (select == 3){    //查看车辆
            cout << "查看车辆" << endl;
            man->showCar();
        }else if (select == 4){
            cout << "清空预约" << endl;
            man->clearFile();
        }else{
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

//学生菜单
void studentMenu(Identity * &student){
    while (true){
        //学生菜单类
        student->operMenu();

        Student *stu = (Student*)student;
        int select;

        cin>> select;

        if (select == 1)    //申请预约
        {
            stu->applyOrder();
        } else if (select == 2)  //查看自身预约
        {
            stu->showMyOrder();
        } else if (select == 3)  //查看所有预约
        {
            stu->showAllOrder();
        } else if (select == 4)   //取消预约
        {
            stu->cancelOrder();
        } else{
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}


//教练菜单
void CoachMenu(Identity * &coach){
    while (true){
        //教练菜单
        coach->operMenu();
        Coach *coa = (Coach *)coach;    //将父类强转为派生类向下转换
        int select = 0;
        cin >> select;
        if (select == 1){
            //查看所有预约
            coa->showAllorder();
        } else if (select == 2){
            //审核预约
            coa->validOrder();
        } else{
            delete coa;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

//登陆功能
void LoginIn(string fileName , int type){
    Identity *person = nullptr;

    ifstream ifs;  //文件操作对象
    ifs.open(fileName , ios::in);  //以只读的形式打开文件

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
        //学员登陆验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            if (id == fId && name == fName && pwd == fPwd){
                cout << "学员验证登陆成功!" << endl;
                system("pause");
                system("cls");
                person = new Student(id , name , pwd);

                //进入学员菜单
                studentMenu(person);
                return;
            }
        }

    }else if (type == 2)
    {
        //教练登录验证
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd){
            if (id == fId && name == fName && pwd == fPwd){
                cout << "教练验证登陆成功！" << endl;
                system("pause");
                system("cls");
                person = new Coach(id , name , pwd);
                CoachMenu(person);
                return;
            }
        }


    } else if (type == 3)
    {
        //管理员登录验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd){
            if (name == fName && pwd == fPwd){
                cout << "管理员验证登陆成功！" << endl;
                system("pause");
                system("cls");

                person = new Manager(name , pwd);

                //进入管理员的子菜单
                mangerMenu(person);
                return;
            }
        }
    }

    cout << "登陆失败！" << endl;
    system("pause");
    system("cls");
    return;
}
