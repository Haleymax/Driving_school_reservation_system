//
// Created by huang on 2024/6/25.
//

#include "../headers/manager.h"
#include "../headers/globalFile.h"
#include "fstream"

//默认构造
Manager::Manager(){

}

//有参构造(管理员姓名 ， 密码)
Manager::Manager(string name , string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//选择菜单
void Manager::operMenu(){
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看车辆              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.清空预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson(){
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号 : ";
    } else{
        fileName = COACH_FILE;
        tip = "请输入职工编号";
    }

    ofs.open(fileName , ios::out | ios::app);  //以追加的形式
    int id;
    string name;
    string pwd;
    cout << "请输入姓名 : " << endl;
    cin >> name;

    cout << "请输入密码 : " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功！" << endl;

    system("pause");
    system("cls");

    ofs.close();
}

//查看账号
void Manager::showPerson(){

}

//查看车辆信息
void Manager::showCar(){

}

//清空预约记录
void Manager::clearFile(){

}