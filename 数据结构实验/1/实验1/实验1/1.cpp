#include <iostream>
using namespace std;
int main()
{
	double a,b,c;
	for ( ; ; )
	{
		cout<<"ȥ�����н��";
	    cin>>a;
	    b=a*(1+0.076);
	    cout<<"Ӧ�����Ľ��:"<<a*0.5*0.076<<endl
		    <<"�µ���н:"<<b<<endl
		    <<"�µ���н:"<<b/12<<endl;
		cout<<"�Ƿ������1����  2����"<<endl;
		cin>>c;
		if (c==2) break;
	}
	return 0;
}