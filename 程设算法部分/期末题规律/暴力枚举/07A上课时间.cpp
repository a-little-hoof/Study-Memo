#include <iostream>
#include<cstring>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int a[1010],b[1010];
    for(int i=1;i<=n;++i)
    {
    	cin>>a[i]>>b[i];
	}
	int maxc=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(b[i]<b[j])
			{
				if(a[j]>b[i])
				continue;
				if(a[j]<=b[i]&&a[j]>a[i])
				maxc=max(maxc,b[i]-a[j]+1);
				if(a[j]<=a[i])
				maxc=max(maxc,b[i]-a[i]+1);
			}
			if(b[i]>b[j])
			{
				if(a[i]>b[j])
				continue;
				if(a[i]<=b[j]&&a[i]>a[j])
				maxc=max(maxc,b[j]-a[i]+1);
				if(a[i]<=a[j])
				maxc=max(maxc,b[j]-a[j]+1);
			}
			if(b[i]==b[j])
			maxc=max(maxc,b[i]-max(a[i],a[j])+1);
			
		}
	}
	cout<<maxc<<endl;
    return 0;
}
