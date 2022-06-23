#include <iostream>
#include<cstring>
using namespace std;

int n,x;
int cnt=0;
bool used[10]={0};
int grid[9]={0};
int en[9]={0};
void find(int num)
{
	if(num==n+1)
	{
		int win=0;
		for(int i=1;i<=n;++i)
		{
			if(grid[i]-en[i]>=x)
			++win;
			else
			--win;
		}
		if(win>0)
		{
			cout<<grid[1];
			for(int i=2;i<=n;++i)
			cout<<" "<<grid[i];
			cout<<endl;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(used[i]==0)
		{
			used[i]=1;
			grid[num]=i;
			find(num+1);
			grid[num]=0;
			used[i]=0;
		}
	}
}
int main() {
	cin>>n>>x;
	for(int i=1;i<=n;++i)
	cin>>en[i];
	find(1);
	return 0;
}
//http://cxsjsx.openjudge.cn/practise2022algo/04C/
//9!=362880