/*
 * File:   main.cpp
 * Author: ���
 * Problem
/*      ĳ��˾ΪԱ������7.6%�Ĺ��ʣ�ͬʱ���±�׼����6���¹��ʣ���д����ʵ�֣�
        ���룺ĳԱ��ȥ�����н��
        �����Ӧ�����Ľ��µ���н���µ���н��
        Ҫ�������û������ظ����㡣

Created on 2015��9��13��, ����11: 58
*/


#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
        double a, b, choose;
        for (;;) {
                cout << "Last-year salary:";
                cin >> a;
                b = a * 1.076;
                cout << "Money that should be added:" << a * 0.5 * 0.076 << endl
                     << "New yearly salary:" << b << endl
                     << "New monthly salary:" << b / 12 << endl;
                cout << "Continue? 1:Yes 2:No." << endl;
                cin >> choose;
                if (choose == 2) {
                        break;
                }
        }
        return 0;
}

