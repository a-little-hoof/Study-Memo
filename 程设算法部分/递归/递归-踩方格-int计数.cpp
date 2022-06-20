#include<iostream>
#include<cstring>
using namespace std;

bool a[1000][1000]={0};
int cnt(int n,int i,int j)
{
	int num=0;
	a[i][j]=1;
	if(n==0)
	{
		a[i][j]=0;
		return 1;
	}
	if(a[i+1][j]==0)
	num+=cnt(n-1,i+1,j);
		
	if(a[i][j-1]==0)
	num+=cnt(n-1,i,j-1);
	if(a[i][j+1]==0)
	num+=cnt(n-1,i,j+1);
	a[i][j]=0;
	return num;
}
int main(){
	int n;
	cin>>n;
	//memset(a,0,sizeof(a));
	cout<<cnt(n,500,500);
	
	return 0;
}
//这种规定步数的问题一般都以步数+1作为结束条件
//要回溯
//走一步，递归
//回溯，找下一步可能