#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long cnt[255][255];
int find(int a,int i)
{
	if(cnt[a][i]!=0)
	return cnt[a][i];
	if(a==0)
	return 1;
	if(i==0)
	return 0;
	if(a<i)
	return find(a,a);
	if(a>=i)
	return find(a-i,i)+find(a,i-1);
	return 0;
	
}//和为a，最大为i
int main(){
	memset(cnt,0,sizeof(cnt));
	int n;
	for(int i=1;i<255;++i)
	for(int j=1;j<255;++j)
	cnt[i][j]=find(i,j); 
	while(cin>>n)
	{
		if(n==0)
		break;
		long long to=0;
		for(int i=1;i<=n;++i)
		{
			if((n-i)%2==0)
			to+=find((n-i)/2,i);//把i写成1 
			//中间数是i，两边的排列方式
		}
		if(n%2==0)
		to+=find(n/2,n/2);
		cout<<n<<" "<<to<<endl;
	}
	return 0;
}
//http://cxsjsx.openjudge.cn/hw202215/A/
//1）关键在于，这道题是找不大于几的排列
//不可从小往大找
//2）先用数组记录一边递归内容省时间
//体现记忆化递归
//
//
//