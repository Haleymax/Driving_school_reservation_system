//
// Created by huang on 2024/6/24.
//

#include "../headers/student.h"

//Ĭ�Ϲ���
Student::Student() {

}

//�вι���(ѧ�š�����������)
Student::Student(int id , string name , string pwd) {
    //��ʼ������
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //��ȡ������Ϣ
    ifstream ifs;
    ifs.open(CAR_FILE , ios::in);

    DrivingRange d;
    while (ifs >> d.m_RangeId && ifs >> d.m_MaxNum){
        vDri.push_back(d);
    }
    ifs.close();

}

//�˵�����
void Student::operMenu() {
    cout << "��ӭѧԱ��" << this->m_Name << "��¼��" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.����ԤԼ              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.�鿴����ԤԼ          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.ȡ��ԤԼ              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.ע����¼              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Student::applyOrder() {

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder() {

}

//ȡ��ԤԼ
void Student::cancelOrder() {

}

//��ʾ���ж���
void Student::showAllOrder() {

}
