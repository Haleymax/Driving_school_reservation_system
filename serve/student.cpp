//
// Created by huang on 2024/6/24.
//

#include "../headers/student.h"

//默认构造
Student::Student() {

}

//有参构造(学号、姓名、密码)
Student::Student(int id , string name , string pwd) {
    //初始化属性
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //获取场地信息
    ifstream ifs;
    ifs.open(CAR_FILE , ios::in);

    DrivingRange d;
    while (ifs >> d.m_RangeId && ifs >> d.m_MaxNum){
        vDri.push_back(d);
    }
    ifs.close();

}

//菜单界面
void Student::operMenu() {
    cout << "欢迎学员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//申请预约
void Student::applyOrder() {

}

//查看我的预约
void Student::showMyOrder() {

}

//取消预约
void Student::cancelOrder() {

}

//显示所有订单
void Student::showAllOrder() {

}
