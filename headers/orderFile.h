//
// Created by huang on 2024/7/4.
//

#ifndef DRIVING_SCHOOL_RESERVATION_SYSTEM_ORDERFILE_H
#define DRIVING_SCHOOL_RESERVATION_SYSTEM_ORDERFILE_H

#endif //DRIVING_SCHOOL_RESERVATION_SYSTEM_ORDERFILE_H

#pragma once
#include "iostream"
#include "fstream"
#include "map"
#include "globalFile.h"

using namespace std;

class OrderFile{
public:

    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录的容器 key ---记录的条数   value ---具体记录的键值对信息
    map<int , map<string , string >> m_orderData;

    //预约条数
    int m_Size;
};