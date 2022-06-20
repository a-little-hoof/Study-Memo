#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[1010];
int total=0;
void cnt(int t,int s)
{
	//cout<<t<<" "<<s<<endl;
	if(t==0)
	{
		total++;
		return;
	}
	for(int i=s;i<=n;++i)
	{
		if(t-a[i]>=0)
		cnt(t-a[i],i+1);
	}
}
int main(){
	int t;
	cin>>n>>t;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	sort(a+1,a+n+1);
	cnt(t,1);
	cout<<total;
	return 0;
}
//http://cxsjsx.openjudge.cn/practise2022algo/01J/
//int型计数递归
//问题在于怎么样不重复，考虑规定大小，先排序，然后从小到大找
//
//
//