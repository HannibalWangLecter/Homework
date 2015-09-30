#include <iostream>
#include <string>
using namespace std;
double jisuan(string a,double b,int c)
{
	if (a=="sa"||a=="SA"||a=="Sa"||a=="su"||a=="SU"||a=="Su")
	{
		return 0.15*c;
	}
	else
	{
		if (b>=8&&b<=18) return c*0.4;
		else return c*0.25;
	}
}

int main()
{
	string a;double b;int c,d;
	do
	{
		cout<<"输入星期几"<<endl
			<<"开始通话的时间（以24小时格式输入）"<<endl
			<<"通话时间（以分钟为单位的整数）:"<<endl;
		cin>>a>>b>>c;
		cout<<"本次通话话费为:"<<jisuan(a,b,c)<<endl
			<<endl
			<<"是否继续计算:"<<endl
			<<"1.是"<<endl
			<<"2.否"<<endl;
		cin>>d;
	}while(d==1);
	return 0;
}