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
	int t,m;
	int n[105]={0};
	int p[105]={0};
	int dp[105][2];
	cin>>t>>m;
	for(int i=1;i<=t;++i)
	{
		cin>>n[i]>>p[i];
		dp[105][0]=0;
		dp[105][1]=0;
	}
	dp[1][0]=n[1];
	dp[1][1]=p[1];
	for(int i=2;i<=t;++i)
	{
		dp[i][0]=max(dp[i-1][0]+n[i],dp[i-1][1]+n[i]-m);
		dp[i][1]=max(dp[i-1][0]+p[i]-m,dp[i-1][1]+p[i]);
	}
	cout<<max(dp[t][0],dp[t][1]);
	return 0;
}