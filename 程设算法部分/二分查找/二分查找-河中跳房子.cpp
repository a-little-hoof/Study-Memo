#include<iostream>
#include<cstring>
using namespace std;

int l,n,m;
int d[50020];
bool judge(int p)
{
	int cnt=0;
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		if(d[i]-tmp<p)
		{
			cnt++;
			if(cnt>m)
			return 0;
		}
		if(d[i]-tmp>=p)
			tmp=d[i];
	}
	if(l-tmp<p)
		cnt++;//第一次提交错是因为这里考虑不周：如果和终点距离小于p直接判断这种情况是错误的
		//实际上多去掉一个就行了
	if(cnt>m)
	return 0;
	return 1;
}
int binary()
{
	int s=0;
	int e=d[n];
	int maxd=0;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(judge(mid))
		{
			s=mid+1;
			maxd=mid;
		}
		else
		{
			e=mid-1;
		}
	}
	return maxd;
}
int main(){
	cin>>l>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>d[i];
	d[n+1]=l;
	d[0]=0;
	cout<<binary()<<endl;
	return 0;
}

//二分查找+贪心http://cxsjsx.openjudge.cn/hw202212/D/
//之前有好多类似的