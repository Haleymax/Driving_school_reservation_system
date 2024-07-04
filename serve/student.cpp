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
    cout << "������һ�����忪��" << endl;
    cout << "���������ԤԼʱ�䣺" << endl;
    cout << "1����һ " << endl;
    cout << "2���ܶ� " << endl;
    cout << "3������ " << endl;
    cout << "4������ " << endl;
    cout << "5������ " << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true){
        cin >> date;
        if (date >= 1 && date <= 5){
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "����������ԤԼ��ʱ��Σ�" << endl;
    cout << "1������" << endl;
    cout << "2������" << endl;

    while (true){
        cin >> interval;
        if (interval >= 1 && interval <= 2){
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "��ѡ�������" << endl;
    cout << "1�Ż���������" << vDri[0].m_MaxNum << endl;
    cout << "2�Ż���������" << vDri[1].m_MaxNum << endl;
    cout << "3�Ż���������" << vDri[2].m_MaxNum << endl;
    while (true){
        cin >> room;
        if (room >= 1 && room <= 3){
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "ԤԼ�ɹ��������" << endl;

    ofstream ofs(ORDER_FILE , ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");
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
