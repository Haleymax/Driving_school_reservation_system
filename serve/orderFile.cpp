//
// Created by huang on 2024/7/4.
//

#include "../headers/orderFile.h"

//构造函数
OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE , ios::in);

    string date;    //日期
    string interval;    //时间段
    string stuId;   //学员编号
    string stuName;     //学员姓名
    string rangId;      //场地编号
    string status;      //预约状态

    this->m_Size = 0;   //预约记录个数
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> rangId && ifs >> status)
}