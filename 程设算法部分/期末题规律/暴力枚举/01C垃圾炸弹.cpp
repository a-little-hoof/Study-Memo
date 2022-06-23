#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
#include<queue>
using namespace std;

struct trash{
	int x;
	int y;
	int num;
};

int main()
{
	int d;
	int n;
	int a[1025][1025]={0};
	trash gar[21];
	cin>>d>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>gar[i].x>>gar[i].y>>gar[i].num;
	}
	int maxnum=0;
	int cnt=0;
	for(int k=1;k<=n;++k)
	{
		for(int i=gar[k].x-d;i<=gar[k].x+d;++i)
		{
			for(int j=gar[k].y-d;j<=gar[k].y+d;++j)
			{
				if(i>=0&&i<1025&&j>=0&&j<1025)
				{
					a[i][j]+=gar[k].num;
					if(a[i][j]>maxnum)
					{
						maxnum=a[i][j];
						cnt=1;
					}
					else if(a[i][j]==maxnum)
					{
						++cnt;
					}
				}
				
			}
		}
	}
	cout<<cnt<<" "<<maxnum<<endl;
    return 0;
}

//需要观察的枚举