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
    cout << "1�����ѧ��" << endl;
    cout << "2�������ʦ" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1){
        fileName = STUDENT_FILE;
        tip = "������ѧ�� : ";
    } else{
        fileName = COACH_FILE;
        tip = "������ְ�����";
    }

    ofs.open(fileName , ios::out | ios::app);  //��׷�ӵ���ʽ
    int id;
    string name;
    string pwd;
    cout << "���������� : " << endl;
    cin >> name;

    cout << "���������� : " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "��ӳɹ���" << endl;

    system("pause");
    system("cls");

    ofs.close();
}

//�鿴�˺�
void Manager::showPerson(){

}

//�鿴������Ϣ
void Manager::showCar(){

}

//���ԤԼ��¼
void Manager::clearFile(){

}