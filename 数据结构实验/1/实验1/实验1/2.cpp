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
		cout<<"�������ڼ�"<<endl
			<<"��ʼͨ����ʱ�䣨��24Сʱ��ʽ���룩"<<endl
			<<"ͨ��ʱ�䣨�Է���Ϊ��λ��������:"<<endl;
		cin>>a>>b>>c;
		cout<<"����ͨ������Ϊ:"<<jisuan(a,b,c)<<endl
			<<endl
			<<"�Ƿ��������:"<<endl
			<<"1.��"<<endl
			<<"2.��"<<endl;
		cin>>d;
	}while(d==1);
	return 0;
}