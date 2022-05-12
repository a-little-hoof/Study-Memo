#include <iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;

int n,f;
double pi[10010];
double maxsol=0.0;
bool cmp(double a,double b)
{
	return a>b;
}
bool judge(double p)
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(cnt>=f+1)
			return 1;
		if(pi[i]<p)
		break;
		cnt+=(int)((pi[i])/p);//强制类型转换int注意作用范围
	}
	if(cnt>=f+1)
		return 1;
	return 0;
}
void binary()
{
	double s=0,e=pi[1];
	while((e-s)>1e-6)
	{
		double mid=s+(e-s)/2;
		if(judge(mid))
		{
			maxsol=mid;
			s=mid+0.0000001;
		}
		else
		{
			e=mid-0.0000001;
		}
	}
}
int main() {
	cin>>n>>f;
	for(int i=1;i<=n;++i)
	{
		double tmp;
		cin>>tmp;
		pi[i]=tmp*tmp*3.141592653589793;//精度问题
	}
	sort(pi+1,pi+n+1,cmp);
	binary();
	cout<<fixed<<setprecision(3)<<maxsol<<endl;
	return 0;
}
//第一次是没注意到二分查找除数为0
//然后发现整体思路出错，以为只能是整数
//之后调成浮点数，忘记修改函数形参为double
//再之后int强制类型转换括号作用范围出错
//再之后是pi的精度问题
//
//

