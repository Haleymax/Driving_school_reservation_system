//
// Created by huang on 2024/6/25.
//

#pragma once
#include "../headers/globalFile.h"
#include "../headers/Identity.h"
#include "student.cpp"
#include "coach.cpp"
#include "manager.cpp"
#include "fstream"
#include "string"

using namespace std;

//����Ա�˵�
void mangerMenu(Identity * &manager){
    while (true){
        //����Ա�˵�
        manager->operMenu();

        Manager *man = (Manager *)manager;
        int select = 0;
        cin >> select;
        if (select == 1){   //����˺�
            cout << "����˺�" << endl;
            man->addPerson();
        } else if (select == 2){  //�鿴�˺�
            cout << "�鿴�˺�" << endl;
            man->showPerson();
        } else if (select == 3){    //�鿴����
            cout << "�鿴����" << endl;
            man->showCar();
        }else if (select == 4){
            cout << "���ԤԼ" << endl;
            man->clearFile();
        }else{
            delete manager;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

//ѧ���˵�
void studentMenu(Identity * &student){
    while (true){
        //ѧ���˵���
        student->operMenu();

        Student *stu = (Student*)student;
        int select = 0;

        cin>> select;

        if (select == 1)    //����ԤԼ
        {
            stu->applyOrder();
        } else if (select == 2)  //�鿴����ԤԼ
        {
            stu->showMyOrder();
        } else if (select == 3)  //�鿴����ԤԼ
        {
            stu->showAllOrder();
        } else if (select == 4)   //ȡ��ԤԼ
        {
            stu->cancelOrder();
        } else{
            delete student;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

//��½����
void LoginIn(string fileName , int type){
    Identity *person = nullptr;

    ifstream ifs;  //�ļ���������
    ifs.open(fileName , ios::in);  //��ֻ������ʽ���ļ�

    //�ļ�������
    if(!ifs.is_open()){
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)  //ѧ����½
    {
        cout << "���������ѧ��" << endl;
        cin >> id;
    } else if (type == 2)   //������½
    {
        cout << "���������ְ����" << endl;
        cin >> id;
    }

    cout << "�������û��� : " << endl;
    cin >> name;

    cout << "���������� : " << endl;
    cin >> pwd;


    if (type == 1)
    {
        //ѧԱ��½��֤
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd){
            if (id == fId && name == fName && pwd == fPwd){
                cout << "ѧԱ��֤��½�ɹ�!" << endl;
                system("pause");
                system("cls");
                person = new Student(id , name , pwd);

                return;
            }
        }

    }else if (type == 2)
    {
        //������¼��֤
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd){
            if (id == fId && name == fName && pwd == fPwd){
                cout << "������֤��½�ɹ���" << endl;
                system("pause");
                system("cls");
                person = new Coach(id , name , pwd);
                return;
            }
        }


    } else if (type == 3)
    {
        //����Ա��¼��֤
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd){
            if (name == fName && pwd == fPwd){
                cout << "����Ա��֤��½�ɹ���" << endl;
                system("pause");
                system("cls");

                person = new Manager(name , pwd);

                //�������Ա���Ӳ˵�
                mangerMenu(person);
                return;
            }
        }
    }

    cout << "��½ʧ�ܣ�" << endl;
    system("pause");
    system("cls");
    return;
}

