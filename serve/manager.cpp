//
// Created by huang on 2024/6/25.
//

#include "../headers/manager.h"
#include "../headers/globalFile.h"
#include "fstream"

//Ĭ�Ϲ���
Manager::Manager(){

}

//�вι���(����Ա���� �� ����)
Manager::Manager(string name , string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;

    //��ʼ������
    this->initVector();

    //��ȡ������Ϣ
    ifstream ifs;
    ifs.open(CAR_FILE , ios::in);

    DrivingRange d;
    while (ifs >> d.m_RangeId && ifs >> d.m_MaxNum){
        vRange.push_back(d);
    }
    cout << "��ǰ��������Ϊ : " << vRange.size() << endl;
    ifs.close();
}

//ѡ��˵�
void Manager::operMenu(){
    cout << "��ӭ����Ա��"<<this->m_Name << "��¼��" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.����˺�              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.�鿴�˺�              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.�鿴����              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.���ԤԼ              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.ע����¼              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson(){
    cout << "����������˺ŵ�����" << endl;
    cout << "1����ӽ���" << endl;
    cout << "2�������ʦ" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    string errorTip;   //�ظ�������ʾ

    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "������ѧ�� : ";
        errorTip = "ѧ���ظ�������������";
    } else{
        fileName = COACH_FILE;
        tip = "������ְ�����";
        errorTip = "ְ������ظ�������������";
    }

    ofs.open(fileName , ios::out | ios::app);  //��׷�ӵ���ʽ
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

    cout << "���������� : " << endl;
    cin >> name;

    cout << "���������� : " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "��ӳɹ���" << endl;

    system("pause");
    system("cls");

    ofs.close();

    //ÿһ��������˺�֮��Ҫ��ʼ����������Ȼ����ӵ��˺��޷�����
    this->initVector();
}

//�鿴�˺�
void Manager::showPerson(){
    cout << "��ѡ��鿴���� : " << endl;
    cout << "1���鿴����ѧ��" << endl;
    cout << "2���鿴������ʦ" << endl;

    int select = 0;

    cin >> select;
    if (select == 1){
        cout << "����ѧ����Ϣ����: " << endl;
        for_each(vStu.begin() , vStu.end() , [](const Student& s){
            cout << "ѧ�ţ�" << s.m_Name << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
        });
    } else{
        cout << "���н�����Ϣ����: " << endl;
        for_each(vCoa.begin() , vCoa.end() , [](const Coach &c){
            cout << "ְ���ţ�" << c.m_EmpId << " ������" << c.m_Name <<" ���룺" << c.m_Pwd << endl;
        });
    }

    system("pause");
    system("cls");

}

//�鿴������Ϣ
void Manager::showCar(){
    cout << "������Ϣ���£�" << endl;
    for (vector<DrivingRange>::iterator it = vRange.begin() ; it != vRange.end() ; it++){
        cout << "���ر�ţ�" << it->m_RangeId << " ���������������" << it->m_MaxNum << endl;
    }
    system("pause");
    system("cls");
}

//���ԤԼ��¼
void Manager::clearFile(){

}

//��ʼ������
void Manager::initVector() {
    //��ȡѧ���ļ�����Ϣ
    ifstream ifs;
    ifs.open(STUDENT_FILE , ios::in);
    if (!ifs.is_open()){
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    this->vStu.clear();
    this->vCoa.clear();

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
        vStu.push_back(s);

    cout << "��ǰѧ������Ϊ : " << vStu.size() << endl;
    ifs.close();     //ѧ����ʼ�����

    //��ȡ��ʦ�ļ���Ϣ
    ifs.open(COACH_FILE , ios::in);

    Coach c;
    while (ifs >> c.m_EmpId && ifs >> c.m_Name && ifs >> c.m_Pwd)
        vCoa.push_back(c);
    cout << "��ǰ������Ϊ : " << vCoa.size() << endl;

    ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
    if (type == 1){
        for (vector<Student>::iterator it = vStu.begin() ; it != vStu.end() ; it++) {
            if (id == it->m_Id)
                return true;    //��ʾ����˺��Ѿ�����
        }
    } else{
        for (vector<Coach>::iterator it = vCoa.begin() ; it != vCoa.end() ; it++ ) {
            if (id == it->m_EmpId)
                return true;   //��ʾ���������ְ�����Ѿ�������
        }
    }
    return false;
}
