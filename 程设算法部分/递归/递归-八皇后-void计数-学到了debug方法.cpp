#include<iostream>
#include<cstring>
using namespace std;

int ans[9];
int num=0;
bool h[9]={0};
void cnt(int p,int n)
{
	if(n==9)
	{
		num++;
//		cout<<"num="<<num<<endl;
//		for(int i=1;i<=8;++i)
//			cout<<ans[i];
//			cout<<endl;
		if(num==p)
		{
			for(int i=1;i<=8;++i)
			cout<<ans[i];
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=8;++i)
	{
		if(h[i]==0)
		{
			h[i]=1;
			ans[n]=i;
			bool t=0;
			for(int j=1;j<n;++j)
			{
				if((n-j)==(ans[n]-ans[j]))
				t=1;
				if((j-n)==(ans[n]-ans[j]))
				t=1;
			}//这里是n不是i
			if(t==0)
			{
				cnt(p,n+1);
			}
			h[i]=0;
			ans[n]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t)
	{
		memset(ans,0,sizeof(ans));
		num=0;
		t--;
		int p;
		cin>>p;
		cnt(p,1);
	}
	
	return 0;
}
//http://bailian.openjudge.cn/practice/2754/
//debug方法 函数中加输入输出
//搞清各个变量的含义