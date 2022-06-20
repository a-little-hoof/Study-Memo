# include<iostream>
#include<cstring> 
#include<cmath>
#include<math.h>
using namespace std;

int R,C;
int rooms[60][60];
int color[60][60];
int maxroomarea=0,roomnum=0;
int roomarea;
void dfs(int i,int k)
{
	if(color[i][k])
	return;
	++roomarea;
	color[i][k]=roomnum;
	if((rooms[i][k]&1)==0)
	dfs(i,k-1);
	if((rooms[i][k]&2)==0)
	dfs(i-1,k);
	if((rooms[i][k]&4)==0)
	dfs(i,k+1);
	if((rooms[i][k]&8)==0)
	dfs(i+1,k);
}

int main()
{
	cin>>R>>C;
	for(int i=1;i<=R;++i)
	for(int k=1;k<=C;++k)
	cin>>rooms[i][k];
	memset(color,0,sizeof(color));
	for(int i=1;i<=R;++i)
		for(int k=1;k<=C;++k)
			{
				if(!color[i][k])
				{
					++roomnum;
					roomarea=0;
					dfs(i,k);
					maxroomarea=max(roomarea,maxroomarea);
				}
			}
	cout<<roomnum<<endl;
	cout<<maxroomarea<<endl;
	return 0;
}

//http://bailian.openjudge.cn/practice/2815/
//用位运算表示墙是否存在
//几个房间：全局变量
//不同颜色区分房间，同时记录是否来过
//
//
//
//