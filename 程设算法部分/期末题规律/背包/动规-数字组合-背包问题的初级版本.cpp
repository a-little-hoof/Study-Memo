#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int t,n;
	cin>>n>>t;
	int a[30];
	int ways[30][1500]={0};
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		ways[i][0]=1;
	}
	ways[0][0]=1;
	for(int i=1;i<=t;++i)
	{
		for(int j=1;j<=n;++j)
		{
			ways[j][i]=ways[j-1][i];
			if(i-a[j]>=0)
			ways[j][i]+=ways[j-1][i-a[j]];
		}
	}
	cout<<ways[n][t];
	return 0;
}
//http://cxsjsx.openjudge.cn/practise2022algo/01J/
//递归问题的动规做法，省时间
//本质上是拆分成子问题，但这里可以用一个数组记录子问题
//ways[w][k]=ways[w][k-1]+ways[w-a[k]][k-1]
//分别对应不取和取
//