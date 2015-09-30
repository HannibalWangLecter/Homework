#include <iostream>
using namespace std;
int main()
{
	double a,b,c;
	for ( ; ; )
	{
		cout<<"去年的年薪：";
	    cin>>a;
	    b=a*(1+0.076);
	    cout<<"应补发的金额:"<<a*0.5*0.076<<endl
		    <<"新的年薪:"<<b<<endl
		    <<"新的月薪:"<<b/12<<endl;
		cout<<"是否继续：1、是  2、否"<<endl;
		cin>>c;
		if (c==2) break;
	}
	return 0;
}