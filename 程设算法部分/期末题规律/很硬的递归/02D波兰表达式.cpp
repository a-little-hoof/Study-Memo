# include<iostream>
#include<cstring> 
#include<cmath>
#include<math.h>
using namespace std;

double cal()
{
	char s[20];
	cin>>s;
	switch(s[0])
	{
		case '*':return cal()*cal();break;
		case '+':return cal()+cal();break;
		case '/':return cal()/cal();break;
		case '-':return cal()-cal();break;
		default:return atof(s);
	}
}
int main()
{
	double v=cal();
	printf("%f\n",v);
	return 0;
}