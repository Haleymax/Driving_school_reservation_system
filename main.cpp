#include <iostream>
#include "serve/globalFun.cpp"

using namespace std;

int main() {

    int select = 0;

    while (true){
        cout << "======================  欢迎进入驾校预约系统  ====================="
             << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学    员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.教    练            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;   //用户选择
        switch (select) {
            case 1:            //学生身份
                LoginIn(STUDENT_FILE , 1);
                break;
            case 2:            //教练身份
                LoginIn(COACH_FILE , 2);
                break;
            case 3:            //管理员身份
                LoginIn(ADMIN_FILE , 3);
                break;
            case 0:            //退出系统
                cout << "欢迎再次使用" << endl;
                system("pause");
                return 0;
            default:
                cout << "输入有误 ， 请重新选择 ！" << endl;
                system("pause");
                system("cls");
                break;
        }

    }
    system("pause");
    return 0;

}


