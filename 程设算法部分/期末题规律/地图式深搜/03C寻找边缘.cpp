#include <iostream>
#include<cstring>
using namespace std;

int r,c;
char map[505][505];
bool visit[505][505];
bool judge(int i,int j)
{
	if(i<1||i>r||j<1||j>c)
	return 0;
	if(visit[i][j])
	return 0;
	if(map[i][j]=='X')
	return 0;
	return 1;
}
void dfs(int i,int j,bool b)
{
	visit[i][j]=1;
	if(!b)
	map[i][j]='X';
	if(judge(i+1,j))
	dfs(i+1,j,b);
	if(judge(i-1,j))
	dfs(i-1,j,b);
	if(judge(i,j+1))
	dfs(i,j+1,b);
	if(judge(i,j-1))
	dfs(i,j-1,b);
}

int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
    	memset(map,0,sizeof(map));
    	memset(visit,0,sizeof(visit));
    	cin>>r>>c;
    	for(int i=1;i<=r;++i)
    	{
    		for(int j=1;j<=c;++j)
    		{
    			cin>>map[i][j];
			}
		}
		for(int i=1;i<=r;++i)
		{
			if(map[i][1]=='O'&&visit[i][1]==0)
			dfs(i,1,1);
			if(map[i][c]=='O'&&visit[i][c]==0)
			dfs(i,c,1);
		}
		for(int i=1;i<=c;++i)
		{
			if(map[1][i]=='O'&&visit[1][i]==0)
			dfs(1,i,1);
			if(map[r][i]=='O'&&visit[r][i]==0)
			dfs(c,i,1);
		}//r、c比较绕
		
		for(int i=2;i<r;++i)
    	{
    		for(int j=2;j<c;++j)
    		{
    			if(map[i][j]=='O'&&visit[i][j]==0)
    			{
    				map[i][j]='X';
				}
			}
		}
		for(int i=1;i<=r;++i)
    	{
    		for(int j=1;j<=c;++j)
    		{
    			cout<<map[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
    return 0;
}
