#include<iostream>
#include<cstring>
using namespace std;

bool a[1000][1000]={0};
int num=0;
void cnt(int n,int i,int j)
{
	a[i][j]=1;
	if(n==1)
	{
		if(a[i+1][j]==0)
		num++;
		if(a[i][j-1]==0)
		num++;
		if(a[i][j+1]==0)
		num++;
		a[i][j]=0;//这里忘记回溯了
		return;
	}
	if(a[i+1][j]==0)
	cnt(n-1,i+1,j);
		
	if(a[i][j-1]==0)
	cnt(n-1,i,j-1);
	if(a[i][j+1]==0)
	cnt(n-1,i,j+1);
	
	a[i][j]=0;//本来也忘了
	
}
int main(){
	int n;
	cin>>n;
	//memset(a,0,sizeof(a));
	cnt(n,500,500);
	cout<<num;
	return 0;
}
// http://bailian.openjudge.cn/practice/4103/
// 不要忘记回溯