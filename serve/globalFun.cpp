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

//��½����
void LoginIn(string fileName , int type){
    Identity *person = nullptr;

    ifstream ifs;  //�ļ���������
    ifs.open("student.txt" , ios::in);  //��ֻ������ʽ���ļ�

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

                return;
            }
        }
    }

    cout << "��½ʧ�ܣ�" << endl;
    system("pause");
    system("cls");
    return;
}