#include <iostream>
using namespace std;
int main()
{
	int a[50],c=0,d,i,j,s[50];
	cin>>d;
	for (i=0;i<d;i++)
	{
		cin>>a[i];
		s[i]=0;
	}
	for (i=0;i<d;i++)
	{
		for (j=0;j<=c;j++)
		{
			if (s[j]+a[i]<=100) 
			{
				s[j]+=a[i];
				cout<<a[i]<<" "<<j+1<<endl;
				break;
			}
		}
		if (j>c) 
		{
			c++;
			s[j]=a[i];
			cout<<a[i]<<" "<<j+1<<endl;
		}
	}
	cout<<c+1<<endl;
	return 0;
}