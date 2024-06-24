//
// Created by huang on 2024/6/24.
//

#ifndef DRIVING_SCHOOL_RESERVATION_SYSTEM_STUDENT_H
#define DRIVING_SCHOOL_RESERVATION_SYSTEM_STUDENT_H

#endif //DRIVING_SCHOOL_RESERVATION_SYSTEM_STUDENT_H

#pragma once
#include "iostream"
#include "Identity.h"

using namespace std;

//学生类
class Student :public Identity{
public:
    //默认构造
    Student();

    //有参构造
    Student(int id , string name , string pwd);

    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看我的所有预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;
};