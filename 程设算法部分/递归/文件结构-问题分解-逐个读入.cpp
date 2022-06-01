#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

string s;
bool stop=0;
int no;
void print(int n)
{
	int num=0;
	string fn[50];
	cin>>s;
	if(s[0]=='#')
	{
		stop=1;
		return;
	}
	if(n==0)
	{
		printf("DATA SET %d:\n",no);
		printf("ROOT\n");
	}
	while(1)
	{
		if(s[0]=='*')
			break;
		else if(s[0]=='d')
		{
			for(int i=1;i<=n+1;++i)
			cout<<"|     ";
			cout<<s<<endl;
			print(n+1);
		}
		else if(s[0]=='f')
		{
			++num;
			fn[num]=s;
		}
		else if(s[0]==']')
			break;
		cin>>s;
	}
	sort(fn+1,fn+num+1);
	for(int i=1;i<=num;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<"|     ";
		cout<<fn[i]<<endl;
	}
	if(n==0)
	cout<<endl;
}

int main(){
	no=0;
	while(1)
	{
		if(stop)
		break;
		++no;
		print(0);
	}
	return 0;
}
//http://cxsjsx.openjudge.cn/hw202213/B/
//逐个读入，遇到dir开启下一层递归
//在每一层递归里记录这一层的文件
//最后输入结束符号也要注意
//
//属于是化为子问题型的递归，不太熟练，可以再做