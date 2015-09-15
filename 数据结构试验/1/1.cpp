/*
 * File:   main.cpp
 * Author: 王昊
 * Problem
/*      某公司为员工普涨7.6%的工资，同时按新标准补发6个月工资，编写程序实现：
        输入：某员工去年的年薪；
        输出：应补发的金额、新的年薪和新的月薪。
        要求：允许用户任意重复计算。

Created on 2015年9月13日, 下午11: 58
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

