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
	int a[102][102];
	memset(a,0,sizeof(a));
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
				if(i>=1&&i<=1025&&j>=1&&j<=1025)
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
//http://cxsjsx.openjudge.cn/practise2022algo/01C/statistics/
//略坑 注意审题 从0到1024 要数组初始化
//从垃圾的角度枚举其周围的坐标