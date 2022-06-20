#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
using namespace std;

int n,k;
int grid[9][9];
bool used[9];
int dfs(int l,int p)
 {
 	//cout<<l<<" "<<p<<endl;
 	int cnt=0;
 	if(p==0)
 		return 1;
 	if(l==n+1)
 		return 0;
 	for(int i=1;i<=n;++i)
 	{
 		if(used[i]==0&&grid[i][l])
 		{
 			used[i]=1;
 			cnt+=dfs(l+1,p-1);
 			used[i]=0;
		}
	}
	cnt+=dfs(l+1,p);
	return cnt;
 }
 
int main()
{
    while(cin>>n>>k)
    {
    	if(n==-1)
    	break;
    	memset(grid,0,sizeof(grid));
    	memset(used,0,sizeof(used));
    	for(int i=1;i<=n;++i)
    	{
    		for(int j=1;j<=n;++j)
    		{
    			char c;
    			cin>>c;
    			if(c=='#')
    			grid[i][j]=1;
    			else
    			grid[i][j]=0;
			}
		}
		cout<<dfs(1,k)<<endl;
	}
    return 0;
}
