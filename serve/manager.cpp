//
// Created by huang on 2024/6/25.
//

#include "../headers/manager.h"
#include "../headers/globalFile.h"
#include "fstream"

//默认构造
Manager::Manager(){

}

//有参构造(管理员姓名 ， 密码)
Manager::Manager(string name , string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化容器
    this->initVector();

    //获取机房信息
    ifstream ifs;
    ifs.open(CAR_FILE , ios::in);

    DrivingRange d;
    while (ifs >> d.m_RangeId && ifs >> d.m_MaxNum){
        vRange.push_back(d);
    }
    cout << "当前机房数量为 : " << vRange.size() << endl;
    ifs.close();
}

//选择菜单
void Manager::operMenu(){
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.查看车辆              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.清空预约              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson(){
    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加教练" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    string errorTip;   //重复错误提示

    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号 : ";
        errorTip = "学号重复，请重新输入";
    } else{
        fileName = COACH_FILE;
        tip = "请输入职工编号";
        errorTip = "职工编号重复，请重新输入";
    }

    ofs.open(fileName , ios::out | ios::app);  //以追加的形式
    int id;
    string name;
    string pwd;
    cout << tip << endl;
    while (true){
        cin >> id;
        bool ret = this->checkRepeat(id , select);

        if (ret){
            cout << errorTip << endl;
        } else{
            break;
        }
    }

    cout << "请输入姓名 : " << endl;
    cin >> name;

    cout << "请输入密码 : " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功！" << endl;

    system("pause");
    system("cls");

    ofs.close();

    //每一次添加完账号之后都要初始化容器，不然新添加的账号无法查重
    this->initVector();
}

//查看账号
void Manager::showPerson(){
    cout << "请选择查看内容 : " << endl;
    cout << "1、查看所有学生" << endl;
    cout << "2、查看所有老师" << endl;

    int select = 0;

    cin >> select;
    if (select == 1){
        cout << "所有学生信息如下: " << endl;
        for_each(vStu.begin() , vStu.end() , [](const Student& s){
            cout << "学号：" << s.m_Name << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
        });
    } else{
        cout << "所有教练信息如下: " << endl;
        for_each(vCoa.begin() , vCoa.end() , [](const Coach &c){
            cout << "职工号：" << c.m_EmpId << " 姓名：" << c.m_Name <<" 密码：" << c.m_Pwd << endl;
        });
    }

    system("pause");
    system("cls");

}

//查看车辆信息
void Manager::showCar(){
    cout << "场地信息如下：" << endl;
    for (vector<DrivingRange>::iterator it = vRange.begin() ; it != vRange.end() ; it++){
        cout << "场地编号：" << it->m_RangeId << " 场地最大车辆容量：" << it->m_MaxNum << endl;
    }
    system("pause");
    system("cls");
}

//清空预约记录
void Manager::clearFile(){

}

//初始化容器
void Manager::initVector() {
    //读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE , ios::in);
    if (!ifs.is_open()){
        cout << "文件读取失败" << endl;
        return;
    }

    this->vStu.clear();
    this->vCoa.clear();

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
        vStu.push_back(s);

    cout << "当前学生数量为 : " << vStu.size() << endl;
    ifs.close();     //学生初始化完成

    //读取老师文件信息
    ifs.open(COACH_FILE , ios::in);

    Coach c;
    while (ifs >> c.m_EmpId && ifs >> c.m_Name && ifs >> c.m_Pwd)
        vCoa.push_back(c);
    cout << "当前教练数为 : " << vCoa.size() << endl;

    ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
    if (type == 1){
        for (vector<Student>::iterator it = vStu.begin() ; it != vStu.end() ; it++) {
            if (id == it->m_Id)
                return true;    //表示这个账号已经存在
        }
    } else{
        for (vector<Coach>::iterator it = vCoa.begin() ; it != vCoa.end() ; it++ ) {
            if (id == it->m_EmpId)
                return true;   //表示这个教练的职工号已经存在了
        }
    }
    return false;
}
