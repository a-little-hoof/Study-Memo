#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int n;
int block[7][8],ans[7][8];
bool check_ans()
{
	for(int i=2;i<=6;++i)
	{
		for(int j=1;j<=6;++j)
		ans[i][j]=(block[i-1][j]+ans[i-1][j]+ans[i-1][j-1]+ans[i-1][j+1]+ans[i-2][j])%2;
	}
	for(int j=1;j<=6;++j)
		if(ans[6][j]==1)
			return 0;
	return 1;
}
//判断解是否可行
 
void solve()
{
	for(int i=0;i<(1<<6);++i)
	{
		int k=i;
		for(int j=1;j<=6;++j)
		{
			ans[1][j]=k%2;
			k/=2;
			//除二代表右移一个
			//求余代表取最后一位 
		}
		if(check_ans())
		break;
	}
	//枚举第一行情况
	 
	//输出答案 
	for(int i=1;i<=5;++i)
	{
		for(int j=1;j<=6;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}
int main() {
	for(int j=1;j<=5;++j)
	for(int k=1;k<=6;++k)
	scanf("%d",&block[j][k]);
	solve();
	return 0;
}

//熄灯问题 http://bailian.openjudge.cn/practice/2811/
//枚举 输入-枚举-判断-输出 
//我的问题： 
//第一行枚举可用位运算 
//其次本解法中求下一行ans很巧妙 
//再者数组开大一些，周围留好空余 ，这样可以减少特殊情况的考虑 
//
//
