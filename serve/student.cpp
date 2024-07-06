//
// Created by huang on 2024/6/24.
//

#include "../headers/student.h"

//默认构造
Student::Student() {

}

//有参构造(学号、姓名、密码)
Student::Student(int id , string name , string pwd) {
    //初始化属性
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //获取场地信息
    ifstream ifs;
    ifs.open(CAR_FILE , ios::in);

    DrivingRange d;
    while (ifs >> d.m_RangeId && ifs >> d.m_MaxNum){
        vDri.push_back(d);
    }
    ifs.close();

}

//菜单界面
void Student::operMenu() {
    cout << "欢迎学员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//申请预约
void Student::applyOrder() {
    cout << "场地周一至周五开放" << endl;
    cout << "请输入你的预约时间：" << endl;
    cout << "1、周一 " << endl;
    cout << "2、周二 " << endl;
    cout << "3、周三 " << endl;
    cout << "4、周四 " << endl;
    cout << "5、周五 " << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true){
        cin >> date;
        if (date >= 1 && date <= 5){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true){
        cin >> interval;
        if (interval >= 1 && interval <= 2){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量：" << vDri[0].m_MaxNum << endl;
    cout << "2号机房容量：" << vDri[1].m_MaxNum << endl;
    cout << "3号机房容量：" << vDri[2].m_MaxNum << endl;
    while (true){
        cin >> room;
        if (room >= 1 && room <= 3){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE , ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "rangId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");
}

//查看我的预约
void Student::showMyOrder() {
    OrderFile of;
    if (of.m_Size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_Size; ++i) {
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id){
            cout << "预约时期： 周" << of.m_orderData[i]["data"];
            cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            string status = "状态：";
            if (of.m_orderData[i]["status"] == "1"){
                status += "审核中";
            } else if (of.m_orderData[i]["status"] == "2"){
                status += "预约成功";
            } else if (of.m_orderData[i]["status"] == "-1"){
                status += "审核未通过，预约失败";
            }else {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
    system("pause");
    system("cls");

}

//取消预约
void Student::cancelOrder() {

}

//显示所有订单
void Student::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; ++i) {
        cout << i + 1 << "、 ";
        cout << "预约时期：周" << of.m_orderData[i]["date"];
        cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << "学号：" << of.m_orderData[i]["stuId"];
        cout << "姓名：" << of.m_orderData[i]["stuName"];
        cout << "机房：" << of.m_orderData[i]["rangId"];

        string status = "状态：";     //0 取消预约  1 审核中   -1 预约失败
        if (of.m_orderData[i]["status"] == "1"){
            status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2") {
            status += "预约成功";
        } else if (of.m_orderData[i]["status"] == "-1") {
            status += "审核未通过，预约失败";
        } else{
            status += "预约已取消";
        }

        cout << status << endl;
    }

    system("pause");
    system("cls");

}
