#include <iostream>
#include "serve/globalFun.cpp"

using namespace std;

int main() {

    int select = 0;

    while (true){
        cout << "======================  ��ӭ�����УԤԼϵͳ  ====================="
             << endl;
        cout << endl << "�������������" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.ѧ    Ա            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.��    ��            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.�� �� Ա            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.��    ��            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "��������ѡ��: ";

        cin >> select;   //�û�ѡ��
        switch (select) {
            case 1:            //ѧ�����
                LoginIn(STUDENT_FILE , 1);
                break;
            case 2:            //�������
                LoginIn(COACH_FILE , 2);
                break;
            case 3:            //����Ա���
                LoginIn(ADMIN_FILE , 3);
                break;
            case 0:            //�˳�ϵͳ
                cout << "��ӭ�ٴ�ʹ��" << endl;
                system("pause");
                return 0;
            default:
                cout << "�������� �� ������ѡ�� ��" << endl;
                system("pause");
                system("cls");
                break;
        }

    }
    system("pause");
    return 0;

}


