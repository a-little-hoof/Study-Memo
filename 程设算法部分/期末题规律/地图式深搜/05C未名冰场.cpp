#include <iostream>
#include<cstring>
using namespace std;

int a[105][105];
int n,m;
int cnt;
bool find(int i,int j)
{
	if(i<1||j<1||i>n||j>m)
	return 0;
	if(a[i][j]==0)
	{
		return 0;
	}
	if(a[i][j])
	{
		a[i][j]=0;//第一件事就应该是标记为旧点
		find(i,j-1);
		find(i,j+1);
		find(i+1,j);
		find(i-1,j);
		find(i+1,j-1);
		find(i+1,j+1);
		find(i-1,j-1);
		find(i-1,j+1);
		return 1;
	}
}
int main()
{
    while(cin>>n>>m)
    {
    	if(n==0)
    	break;
    	memset(a,0,sizeof(a));
    	cnt=0;
    	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			char c;
			cin>>c;
			if(c=='*')
			a[i][j]=0;
			else
			a[i][j]=1;
		}
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]==1&&find(i,j))
			++cnt;
		}	
		cout<<cnt<<endl;
	}
	

    return 0;
}