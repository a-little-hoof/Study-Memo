# include<iostream>
#include<cstring> 
using namespace std;
 
int main()
{
	int n,x;
	cin>>n>>x;
	int dp[10010];
	int a[250];
	bool flag[250]={0};
	bool mark=0;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=x;j>0;--j)
		{
			if(j>=a[i])
			dp[j]+=dp[j-a[i]];//计算n个数合成i有几种
		}
	}
	int cnt=0;
	int tmp[10010];
	for(int i=1;i<=n;++i)//刨去a[i]
	{
		memcpy(tmp,dp,sizeof(tmp));
		for(int j=1;j<=x;++j)
		{
			if(j>=a[i])
			tmp[j]-=tmp[j-a[i]];//tmp[j]的含义是不包含a[i]和为j的可能数
		}//第二次动规记录每次刨去一个数后有几种方法，这次动规要利用第一次结果
		if(tmp[x]==0)
		{
			++cnt;
			flag[i]=1;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;++i)
	{
		if(flag[i])
		{
			if(mark==0)
			cout<<a[i];
			else
			cout<<" "<<a[i];
			mark=1;
		}
	}
	cout<<endl;
	return 0;
}
//http://cxsjsx.openjudge.cn/hw202215/B/
//变态背包
//两重动规
//离谱
//第一重：n个数，和为指定数的方法总数，一维数组滚动
//第二重：刨去一个数剩余和为指定数的方法总数
//