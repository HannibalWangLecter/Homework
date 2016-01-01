//	编写一个程序计算长途电话费。电话费根据以下费率计算：
//	周一到周五，上午八点到下午六点之间打出的任何电话都按每分钟0.4元收取；
//	周一到周五，上午八点之前到下午六点之后打出的任何电话都按每分钟0.25元收取；
//	周六和周日，打出的任何电话都按每分钟0.15元收取。
//      要求：
//	输入时，应指定当前是星期几、开始通话的时间（以24小时格式输入）、通话时间（以分钟为单位的整数）；
//	输入星期几时，采用如下格式，将它们存储在char类型的一个变量中：Mo、Tu、We、Th、Fr、Sa、Su，务必允许用户采用大写、小写或者大小写混合的形式输入；
//	程序应包含一个循环，允许用户重复这一计算，直到他们表示操作完毕为止。
//

#include <iostream>
#include <string>//using strlwr function(in later edition i shall do that)
using namespace std;

double calculate(string a,double b,int c);


int main(int argc, char** argv)
{
	string week;
	doubleS starttime;
	int calltime,choose;
	do
	{
		cout<<"Please input the exact weekday of a week(like Mo、Tu、We、Th、Fr、Sa、Su):"<<endl
			<<"starttime(24h format)"<<endl
			<<"Phonecall period(integer divided by minutes"<<endl;
		cin>>week>>starttime>>calltime;
		cout<<"Phonecall fee is:RMB "<<calculate(week,starttime,calltime)<<endl
			<<"    Continue? 1.Y	2.N"<<endl;
		cin>>choose;
	}while(choose==1);//excute loop
}

double calculate(string a,double b,int c)
{
	if (a=="sa"||a=="SA"||a=="Sa"||a=="sA"||a=="su"||a=="SU"||a=="Su"||a=="sU")//confirm weekday
	{
		return 0.15*c;
	}
	else
	{
		if (b>=8&&b<=18) return c*0.4;
		else return c*0.25;
	}
}
