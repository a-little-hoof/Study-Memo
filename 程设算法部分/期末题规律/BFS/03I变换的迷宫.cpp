#include <iostream>
#include<cstring>
#include<queue>
using namespace std;

int r,c,k;
char maze[105][105];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool gone[105][105][12];
bool judge(int i,int j,int t)
{
	if(i<1||i>r||j<1||j>c)
	return 0;
	if(maze[i][j]=='#'&&t%k)
	return 0;
	if(gone[i][j][t%k])
	return 0;
	return 1;
}
struct node{
	int h,l;
	int t;
	node(int _h,int _l,int _t):h(_h),l(_l),t(_t){};
};
int main()
{
    int T;
    cin>>T;
    while(T)
    {
    	--T;
    	cin>>r>>c>>k;
    	int si,sj;
    	memset(maze,0,sizeof(maze));
    	memset(gone,0,sizeof(gone));
    	for(int i=1;i<=r;++i)
    	{
    		for(int j=1;j<=c;++j)
    		{
    			cin>>maze[i][j];
    			if(maze[i][j]=='S')
    			{
    				si=i;
    				sj=j;
				}
			}
		}
		queue<node> q;
		bool flag=1;
		q.push(node(si,sj,0));
		gone[si][sj][0]=1;
		while(!q.empty())
		{
			node tmp=q.front();
			for(int i=0;i<4;++i)
			{
				int time=tmp.t+1;
				int nowh=tmp.h+dir[i][0];
				int nowl=tmp.l+dir[i][1];
				if(judge(nowh,nowl,time))
				{
					if(maze[nowh][nowl]=='E')
					{
						cout<<time<<endl;
						flag=0;
						break;
					}
					gone[nowh][nowl][time%k]=1;
					q.push(node(nowh,nowl,time));
				}
			}
			if(flag==0)
			break;
			q.pop();
		}
		if(flag)
		cout<<"Oop!"<<endl;
	}

    return 0;
}
//q.push q.front q.pop
//注意判重的条件