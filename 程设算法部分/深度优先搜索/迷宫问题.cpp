# include<iostream>
#include<cstring> 
#include<cmath>
#include<math.h>
using namespace std;

int maze[6][6];
int ans[30][2];
int out[30][2];
bool flag[6][6];
int minlen;
int len;
void dfs(int i,int j)
{
	if(i<1||j<1||i>5||j>5)
	return;
	if(flag[i][j])
	return;
	flag[i][j]=1;
	++len;
	ans[len][0]=i;
	ans[len][1]=j;
	if(i==5&&j==5)
	{
		if(len<minlen)
		{
			minlen=len;
			memcpy(out,ans,sizeof(out));
		}
		ans[len][0]=0;
		ans[len][1]=0;
		--len;
		flag[i][j]=0;
		return;
	}
	if(maze[i][j-1]==0)
	dfs(i,j-1);
	if(maze[i][j+1]==0)
	dfs(i,j+1);
	if(maze[i+1][j]==0)
	dfs(i+1,j);
	if(maze[i-1][j]==0)
	dfs(i-1,j);
	ans[len][0]=0;
	ans[len][1]=0;
	--len;
	flag[i][j]=0;	
	
}
int main()
{
	for(int i=1;i<=5;++i)
	for(int j=1;j<=5;++j)
	cin>>maze[i][j];
	memset(ans,0,sizeof(ans));
	memset(flag,0,sizeof(flag));
	minlen=100;
	len=0;
	dfs(1,1);
	for(int i=1;i<=minlen;++i)
	{
		printf("(%d, %d)\n",out[i][0]-1,out[i][1]-1);
	}
	return 0;
}
