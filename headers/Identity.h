//
// Created by huang on 2024/6/24.
//

#ifndef DRIVING_SCHOOL_RESERVATION_SYSTEM_IDENTITY_H
#define DRIVING_SCHOOL_RESERVATION_SYSTEM_IDENTITY_H

#endif //DRIVING_SCHOOL_RESERVATION_SYSTEM_IDENTITY_H

#pragma once
#include "iostream"

using namespace std;

//抽象身份类
class Identity {
public:
    //操作菜单
    virtual void operMenu() = 0;

    string m_Name;   //用户名
    string m_Pwd;    //密码
};