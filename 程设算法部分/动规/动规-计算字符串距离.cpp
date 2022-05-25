#include<iostream>
#include<cstring>
using namespace std;
int grid[1010][1010];//放到循环里就崩溃
int main(){
	int n;
	cin>>n;
	while(n)
	{
		--n;
		char s1[1020];
		char s2[1020];
		cin>>s1>>s2;
		memset(grid,0,sizeof(grid));
		int len1=strlen(s1);
		int len2=strlen(s2);
		for(int i=1;i<=len1;++i)
		{
			grid[i][0]=i;
		}
		for(int i=1;i<=len2;++i)
		{
			grid[0][i]=i;
		}
		for(int i=1;i<=len1;++i)
		{
			for(int j=1;j<=len2;++j)
			{
				if(s1[i-1]==s2[j-1])
				grid[i][j]=grid[i-1][j-1];
				else
				grid[i][j]=grid[i-1][j-1]+1;
				grid[i][j]=min(grid[i][j],grid[i-1][j]+1);
				grid[i][j]=min(grid[i][j],grid[i][j-1]+1);
			}
		}
		cout<<grid[len1][len2]<<endl;
	}
	return 0;
}
// http://cxsjsx.openjudge.cn/practise2022algo/01H/
//
//
//