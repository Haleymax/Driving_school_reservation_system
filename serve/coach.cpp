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

}

//查看所有预约
void Coach::showAllorder(){

}

//审核预约
void Coach::validOrder(){

}