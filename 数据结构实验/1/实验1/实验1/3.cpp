#include <iostream>
using namespace std;
int main()
{
	double a,b;
	char c='0';
	cin>>a;
	while(c!='=')
	{
		cin>>c;
		switch (c)
		{
		case '+':
			cin>>b;
			a=a+b;
			break;
		case '-':
			cin>>b;
			a=a-b;
			break;
		case '*':
			cin>>b;
			a=a*b;
			break;			
		case '/':
			cin>>b;
			a=a/b;
			if (b==0)
			{
				cout<<"������ĸΪ�㣡"<<endl;
				return 0;
			}
			break;
		case '=':
			break;
		default:
			cout<<"�Ƿ����룡"<<endl;
			return 0;
		}
	}
	cout<<a<<endl;
	return 0;
}
