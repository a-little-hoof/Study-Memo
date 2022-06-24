# include<iostream>
#include<cstring> 
#include<cmath>
#include<math.h>
using namespace std;

bool used[110];
bool vi[110];
char str[110];
int len;
void f(int s)
{
	vi[s]=1;
	for(int i=s+1;i<len;++i)
	{
		if(str[i]=='('&&used[i]==0&&vi[i]==0)
		f(i);
		if(str[i]==')'&&used[i]==0)
		{
			used[i]=1;
			used[s]=1;
			return;
		}
	}
}
int main()
{
	while(scanf("%s",str)!=EOF)
	{
		//cout<<str<<endl;
		memset(used,0,sizeof(used));
		memset(vi,0,sizeof(vi));
		len=strlen(str);
		int i=0;
		for(i=0;i<len;++i)
		{
			if(str[i]=='('&&used[i]==0)
			f(i);
		}
		cout<<str<<endl;
		for(int t=0;t<len;++t)
		{
			if(used[t]==0)
			{
				if(str[t]=='(')
				cout<<'$';
				else if(str[t]==')')
				cout<<'?';
				else
				cout<<" ";
				
			}
			else
			cout<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}
//http://cxsjsx.openjudge.cn/practise2022algo/02E/
//说说哪错了吧
//第一次只从一个左括号开始，递归不全
//第二次没有记录已经递归过的左括号，栈爆了
//第三次是脑残输入输出
//然后变量是k写成i
//
//直接做也可