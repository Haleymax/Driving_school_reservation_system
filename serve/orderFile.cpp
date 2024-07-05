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
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> rangId && ifs >> status){
        string key;
        string value;
        map<string , string > m;
        int pos = date.find(":");

        if (pos != -1){
            key = date.substr(0,pos);
            value = date.substr(pos + 1 , date.size() - pos - 1);
            m.insert(make_pair(key , value));
        }

        pos = interval.find(":");
        if (pos != -1){
            key = interval.substr(0 , pos);
            value = interval.substr(pos + 1 , interval.size() - pos -1);
            m.insert(make_pair(key , value));
        }
    }
}