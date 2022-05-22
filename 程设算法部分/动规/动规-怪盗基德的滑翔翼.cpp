#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int n;
int h[200];


int main(){
	int k;
	cin>>k;
	while(k)
	{
		--k;
		cin>>n;
		int f[200],b[200];
		for(int i=1;i<=n;++i)
		{
			cin>>h[i];
			f[i]=1;
			b[i]=1;
		}
		int maxnum=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<i;++j)
			{
				if(h[j]>h[i])
				f[i]=max(f[i],f[j]+1);
			}
			maxnum=max(maxnum,f[i]);
		}
		for(int i=n;i>=1;--i)
		{
			for(int j=n;j>i;--j)
			{
				if(h[j]>h[i])
				b[i]=max(b[i],b[j]+1);
			}
			maxnum=max(maxnum,b[i]);
		}
		cout<<maxnum<<endl;
		
	}
	return 0;
}

// http://cxsjsx.openjudge.cn/hw202214/C/
//
//