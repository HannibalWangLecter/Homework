// ���ʽ��ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Caculate.h"
using namespace std;

int main(int argc, char* argv[])
{

	//Title
	cout << "**********Expression Calculation Program****Designed by ���(AnHui Normal University)*********" << endl;

	while (1) {
		Calculator Test;
		Test.Input();
		Test.DoOperator();
		Test.OutResult();
	}
	return 0;
}

