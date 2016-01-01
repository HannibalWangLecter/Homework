// 表达式求值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Caculate.h"
using namespace std;

int main(int argc, char* argv[])
{

	//Title
	cout << "**********Expression Calculation Program****Designed by 王昊(AnHui Normal University)*********" << endl;

	while (1) {
		Calculator Test;
		Test.Input();
		Test.DoOperator();
		Test.OutResult();
	}
	return 0;
}

