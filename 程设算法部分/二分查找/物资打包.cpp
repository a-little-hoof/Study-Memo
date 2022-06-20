#include <iostream>
#include<cstring>
using namespace std;

int n,m;
int a[1010];
bool binary(int p)
{
	int total=0;
	for(int i=1;i<=n;++i)
	{
		total+=(a[i]/p);
		if(a[i]%p)
		++total;
		if(total>m)
		return 0;
	}
	return 1;
}
int main() {
	cin>>n>>m;
	int maxw=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		maxw=max(maxw,a[i]);
	}
	int e=maxw;
	int s=1;
	int x=100000000;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(binary(mid)==0)
		{
			s=mid+1;
		}
		else
		{
			x=min(x,mid);
			e=mid-1;
		}
	}
	cout<<x<<endl;
	return 0;
}

//http://cxsjsx.openjudge.cn/practise2022algo/04F/