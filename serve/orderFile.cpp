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

        pos = stuId.find(":");
        if (pos != -1){
            key = stuId.substr(0 , pos);
            value = stuId.substr(pos + 1 , stuId.size() - pos - 1);
            m.insert(make_pair(key , value));
        }

        pos = stuName.find(":");
        if (pos != -1){
            key = stuName.substr(0 , pos);
            value = stuName.substr(pos + 1 , stuName.size() - pos - 1);
            m.insert(make_pair(key , value));
        }

        pos = rangId.find(":");
        if (pos != -1){
            key = rangId.substr(0 , pos);
            value = rangId.substr(pos + 1 , rangId.size() - pos -1);
            m.insert(make_pair(key , value));
        }

        pos = status.find(":");
        if (pos != -1){
            key = status.substr( 0 , pos);
            value = status.substr(pos + 1 , status.size() - pos - 1);
            m.insert(make_pair(key , value));
        }

        this->m_orderData.insert(make_pair(this->m_Size , m));
        this->m_Size++;
    }

    ifs.close();
}