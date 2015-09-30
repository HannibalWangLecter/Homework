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
		cout<<"输入身高、体重和年龄:";
		cin>>h>>w>>age;
		cout<<"帽子的尺码:"<<maozi(h,w,age)<<endl
			<<"上衣尺码:"<<shangyi(h,w,age)<<endl
			<<"腰围尺码:"<<yaowei(h,w,age)<<endl;
		cout<<"是否继续输入：1、是  2、否"<<endl;
		cin>>a;
		if (a==2) break;
	}
	return 0;
}



