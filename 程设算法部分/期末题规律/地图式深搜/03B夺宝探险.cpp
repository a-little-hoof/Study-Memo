#include <iostream>
#include<cstring>
using namespace std;

int M,N,K;
int maze[21][21];
int maxt=0;
bool t[101];
bool pan(int i,int j)
{
	if(i<1||j<1||i>M||j>N)
	return 0;
	if(t[maze[i][j]])
	return 0;
	return 1;
}
void dfs(int i,int j,int cnt)
{
	maxt=max(maxt,cnt);
	t[maze[i][j]]=1;
	if(pan(i+1,j))
		dfs(i+1,j,cnt+1);
	if(pan(i-1,j))
		dfs(i-1,j,cnt+1);
	if(pan(i,j+1))
		dfs(i,j+1,cnt+1);
	if(pan(i,j-1))
		dfs(i,j-1,cnt+1);
	t[maze[i][j]]=0;
}
int main()
{
 	cin>>M>>N>>K;
 	memset(maze,0,sizeof(maze));
 	memset(t,0,sizeof(t));
	for(int i=1;i<=M;++i)
	for(int j=1;j<=N;++j)
	{
		cin>>maze[i][j];
	}
	dfs(1,1,1);
	cout<<maxt<<endl;
	    
    return 0;
}
