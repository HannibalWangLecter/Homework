#include <iostream>
using namespace std;
double maozi(double h,double w,int age)
{
	return w/h*2.9;
}

double shangyi(double h,double w,int age)
{
	if (age<=30) return h*w/288;
	else return h*w/288+(age-30)/10*(1.0/8);
}

double yaowei(double h,double w,int age)
{
	if (age<=28) return w/5.7;
	else return w/5.7+(age-28)/2*0.1;
}

int main()
{
	double h,w;
	int age,a;
	for ( ; ; )
	{
		cout<<"������ߡ����غ�����:";
		cin>>h>>w>>age;
		cout<<"ñ�ӵĳ���:"<<maozi(h,w,age)<<endl
			<<"���³���:"<<shangyi(h,w,age)<<endl
			<<"��Χ����:"<<yaowei(h,w,age)<<endl;
		cout<<"�Ƿ�������룺1����  2����"<<endl;
		cin>>a;
		if (a==2) break;
	}
	return 0;
}



