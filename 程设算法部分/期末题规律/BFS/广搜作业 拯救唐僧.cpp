#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
#include<queue>
using namespace std;

struct sit{
	int r;
	int c;
	int move;
	int keys;
	int snakesit;
	sit(int i,int j,int _move,int _keys,int _snakesit):r(i),c(j),move(_move),keys(_keys),snakesit(_snakesit){};
    bool operator <(sit a)const{
		return move>a.move;
	}
};
char maze[110][110];
int N;
int M;
int snake[110][110];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool reach[110][110][40][10];
bool judge(int i,int j,int key,int snakesit)
{
	if(i<=0||j<=0||i>N||j>N||maze[i][j]=='#'||reach[i][j][snakesit][key]==1)
	return 0;
	
	return 1;
}
int main()
{
	while(cin>>N>>M)
	{
		if(N==0)
		break;
		memset(maze,0,sizeof(maze));
		memset(reach,0,sizeof(reach));
		int si,sj;
		int cnt=0;
		int inisnake=0;
		for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			cin>>maze[i][j];
			if(maze[i][j]=='K')
			{
				si=i;
				sj=j;
			}
			if(maze[i][j]=='S')
			{
				++cnt;
				snake[i][j]=cnt;
				inisnake+=(1<<cnt);
			}
		}
		priority_queue<sit> q;
		q.push(sit(si,sj,0,0,inisnake));
		bool flag=0;
		while(!q.empty())
		{
			sit tmp=q.top();
			if(maze[tmp.r][tmp.c]=='T'&&tmp.keys==M)
			{
				cout<<tmp.move<<endl;
				flag=1;
				break;
			}
			for(int i=0;i<4;++i)
			{
				if(judge(tmp.r+dir[i][0],tmp.c+dir[i][1],tmp.keys,tmp.snakesit))
				{
					reach[tmp.r+dir[i][0]][tmp.c+dir[i][1]][tmp.snakesit][tmp.keys]=1;
					if(maze[tmp.r+dir[i][0]][tmp.c+dir[i][1]]=='S'&&(tmp.snakesit&(1<<snake[tmp.r+dir[i][0]][tmp.c+dir[i][1]])))
					{
						q.push(sit(tmp.r+dir[i][0],tmp.c+dir[i][1],tmp.move+2,tmp.keys,tmp.snakesit-(1<<snake[tmp.r+dir[i][0]][tmp.c+dir[i][1]])));
					}
					else if(maze[tmp.r+dir[i][0]][tmp.c+dir[i][1]]=='0'+tmp.keys+1)
					{
						q.push(sit(tmp.r+dir[i][0],tmp.c+dir[i][1],tmp.move+1,tmp.keys+1,tmp.snakesit));
					}
					else
						q.push(sit(tmp.r+dir[i][0],tmp.c+dir[i][1],tmp.move+1,tmp.keys,tmp.snakesit));
				}
			}
			
		
			q.pop();
		}
		if(!flag)
		cout<<"impossible"<<endl;
	}
    return 0;
}
//优先队列：push top pop
//不要直接在原节点上修改