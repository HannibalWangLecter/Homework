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
				cout<<"除法分母为零！"<<endl;
				return 0;
			}
			break;
		case '=':
			break;
		default:
			cout<<"非法输入！"<<endl;
			return 0;
		}
	}
	cout<<a<<endl;
	return 0;
}
