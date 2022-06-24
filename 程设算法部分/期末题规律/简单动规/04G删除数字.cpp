#include<cstdio>
#include<iostream>
#include<cstring>
#include <string> 
#include<algorithm>
using namespace std;



int main(){
	int test;
	cin>>test;
	while(test)
	{
		--test;
		int n;
		cin>>n;
		int num[1005];
		int dp[1005][1005];//前：前几个数 后：删去几个  这样情况下匹配的最多个数 
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			cin>>num[i];
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				if(num[i]==i-j)
				dp[i][j]=dp[i-1][j]+1;
				else
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
			}
		}
		cout<<*max_element(dp[n],dp[n]+n+1)<<endl;
	}
	return 0;
}
