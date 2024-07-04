//
// Created by huang on 2024/7/4.
//

#include "../headers/orderFile.h"

//构造函数
OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE , ios::in);

    string name;    //日期
    string interval;    //时间段
    string stuId;   //学员编号
    string stuName;     //学员姓名
    string rangId;      //场地编号
    string status;      //预约状态


}