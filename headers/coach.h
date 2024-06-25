//
// Created by huang on 2024/6/25.
//

#ifndef DRIVING_SCHOOL_RESERVATION_SYSTEM_COACH_H
#define DRIVING_SCHOOL_RESERVATION_SYSTEM_COACH_H

#endif //DRIVING_SCHOOL_RESERVATION_SYSTEM_COACH_H

#pragma once
#include "iostream"
#include "Identity.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Coach : public Identity{
public:
    //默认构造
    Coach();

    //有参构造(职工编号 ， 姓名 ， 密码)
    Coach(int empId , string name , string pwd);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllorder();

    //审核预约
    void validOrder();


};