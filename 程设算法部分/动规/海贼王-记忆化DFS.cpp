#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
using namespace std;

int n;
int grid[20][20];
bool used[20];
int mint;
int dp[20][1<<18];
void dfs(int p,int cnt,int cur,int visit)
 {
 	if(cnt==n-1)
 	{
 		mint=min(mint,cur+grid[p][n]);
		return;
	}
 	else
 	{
 		for(int i=2;i<n;++i)
	 	{
	 		if(used[i]==0&&cur+grid[p][i]<dp[i][visit+(1<<i)])
	 		{
	 			used[i]=1;
	 			visit+=(1<<i);
	 			dp[i][visit]=cur+grid[p][i];
	 			dfs(i,cnt+1,cur+grid[p][i],visit);
	 			visit-=(1<<i);
	 			used[i]=0;
			}
		}
	}
 }
 
int main()
{
	cin>>n;
    mint=0x3f3f3f;
   	memset(grid,0,sizeof(grid));
    memset(used,0,sizeof(used));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=n;++j)
    		cin>>grid[i][j];
    for(int i=0;i<20;++i)
    for(int j=0;j<(1<<18);++j)
    dp[i][j]=0x3f3f3f;
    dfs(1,1,0,0);
    cout<<mint<<endl;
    return 0;
}

//http://cxsjsx.openjudge.cn/hw202216/C/
//记忆化递归+状态压缩
//如何减少搜索 记录到过相同岛屿且重点一样的最短方式
//如果之后达到此状态时比最短方式大 剪枝
//但是要注意，如果到达的岛屿一样，但是终点不一样的话，不是同一个状态
//所以dp是二维数组
//留一个疑问：line23判断条件如果是> continue就会超时？
//然后只用考虑中间n-2个岛屿，函数结构
//
//