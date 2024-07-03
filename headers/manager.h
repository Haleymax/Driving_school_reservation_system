//
// Created by huang on 2024/6/25.
//

#ifndef DRIVING_SCHOOL_RESERVATION_SYSTEM_MANAGER_H
#define DRIVING_SCHOOL_RESERVATION_SYSTEM_MANAGER_H

#endif //DRIVING_SCHOOL_RESERVATION_SYSTEM_MANAGER_H

#pragma once
#include "iostream"
#include "string"
#include "Identity.h"
#include "vector"
#include "student.h"
#include "coach.h"
#include "globalFile.h"
#include "algorithm"
#include "drivingRange.h"

using namespace std;

class Manager : public Identity{
public:

    //默认构造
    Manager();

    //有参构造(管理员姓名 ， 密码)
    Manager(string name , string pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看车辆信息
    void showCar();

    //清空预约记录
    void clearFile();

    //检测重复 参数:(传入id ， 传入类型) 返回值 : (true 代表有重复 ， flase代表没有重复)
    bool checkRepeat(int id , int type);

    //初始化容器
    void initVector();

    //学生容器
    vector<Student> vStu;

    //教练容器
    vector<Coach> vCoa;

    //场地容器
    vector<DrivingRange> vRange;
};