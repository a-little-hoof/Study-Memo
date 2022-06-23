#include <iostream>
#include<cstring>
using namespace std;

int N,M;
int w[1010];
bool ok(int x)
{
	int cnt=0;
	for(int i=1;i<=N;++i)
	{
		cnt+=(w[i])/x;
		if(w[i]%x)
		++cnt;
		if(cnt>M)
		return 0;
	}
	return 1;
}

int main()
{
    cin>>N>>M;
    int maxw=0;
    for(int i=1;i<=N;++i)
    {
    	cin>>w[i];
    	maxw=max(maxw,w[i]);
	}
	int s=1,e=maxw;
	int ans=e;
	while(s<=e)//改成小于就错 
	{
		int mid=s+(e-s)/2;
		if(ok(mid))
		{
			ans=mid; 
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	cout<<ans<<endl;
    return 0;
}
