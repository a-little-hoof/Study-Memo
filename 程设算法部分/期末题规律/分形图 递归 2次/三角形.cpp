#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char grid[2500][2500];
void f(int i,int j,int n)
{
	if(n==1)
	{
		grid[i][j]='/';
		grid[i][j+1]='\\';
		grid[i+1][j-1]='/';
		grid[i+1][j]='_';
		grid[i+1][j+1]='_';
		grid[i+1][j+2]='\\';//\\转义
		return;
	}
	f(i,j,n-1);
	f(i+pow(2,n-1),j-pow(2,n-1),n-1);
	f(i+pow(2,n-1),j+pow(2,n-1),n-1);
}
int main(){
	int n;
	while(cin>>n)
	{
		if(n==0)
		break;
		memset(grid,0,sizeof(grid));
		int t=pow(2,n);
		for(int i=0;i<=t;++i)
			for(int j=0;j<=2*t;++j)//一直锟斤拷锟斤拷锟斤拷为锟斤拷锟斤拷锟劫筹拷2 锟揭帮拷锟矫伙拷锌崭锟� 锟斤拷锟斤拷也锟斤拷1锟斤拷锟斤拷锟斤拷状 
				grid[i][j]=' ';
		f(0,pow(2,n)-1,n);
		for(int i=0;i<=t-1;++i)
		{
			for(int j=0;j<=i+t;++j)
			{
				cout<<grid[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}

//http://cxsjsx.openjudge.cn/hw202213/C/