//
// Created by huang on 2024/6/25.
//

#include "../headers/coach.h"

//默认构造
Coach::Coach() {

}

//有参构造
Coach::Coach(int empId , string name , string pwd) {
    //初始化属性
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//菜单界面
void Coach::operMenu(){
    cout << "欢迎教练：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.查看所有预约          |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.审核预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Coach::showAllorder(){
    OrderFile of;
    if (of.m_Size == 0){
        cout << "无法预约" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_Size; ++i) {
        cout << i + 1 << "、 ";
        cout << "预约时间：周" << of.m_orderData[i]["date"];
        cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号：" << of.m_orderData[i]["stuId"];
        cout << " 姓名：" << of.m_orderData[i]["stuName"];
        cout << " 场地：" << of.m_orderData[i]["rangeId"];
        string status = "状态： ";
        if (of.m_orderData[i]["status"] == "1"){
            status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2"){
            status += "预约成功";
        } else if (of.m_orderData[i]["status"] == "-1"){
            status += "审核未通过，预约失败";
        } else{
            status += "预约已取消";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");
}

//审核预约
void Coach::validOrder(){
    OrderFile of;
    if (of.m_Size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }


    cout << "待审核的预约记录如下：" << endl;

}