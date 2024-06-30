//
// Created by huang on 2024/6/25.
//

#include "../headers/manager.h"

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