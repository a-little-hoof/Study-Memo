#include<cstdio>
#include<iostream>
#include<cstring>
#include <string> 
#include<algorithm>
using namespace std;

int n,k;
int a[105]={};
int dp[1005]={};

int main(){
	while(cin>>n>>k){
		if(n==0 &&k==0)
			break;
		for(int i=1;i<=n;i++)
			cin>>a[i]; 
		dp[0]=0;
		for(int i=1;i<=k;i++)
		{
			dp[i]=n+1;//合成i的最少个数 
			for(int j=1;j<=n;j++)
			{
				if(a[j]<=i)
					dp[i] = min(dp[i], dp[i-a[j]]+1);
			}//都枚举一遍，找出合成当前数的最少个数 
		} 
		if(dp[k] == n+1)
			cout<<-1<<endl;
		else
			cout<<dp[k]<<endl;
	}
	return 0;
}
