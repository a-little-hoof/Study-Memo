#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int w[3500]={0};
	int d[3500]={0};
	//int best[12900][3410]={0};超内存 
	int best[13000]={0};
	for(int i=1;i<=n;++i)
	{
		cin>>w[i]>>d[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=0;--j)
		{
			if(w[i]<=j)
			best[j]=max(best[j],best[j-w[i]]+d[i]);
		}
	}
	cout<<best[m];
	return 0;
}
//http://cxsjsx.openjudge.cn/hw202215/C/
//递推式：best[i][j]=max(best[i][j-1],best[i-w[j]][j-1])前面的表示总重，后面的表示在前j给里选
//对应本解法的递推式：best[i][j]=max(best[i-1][j],best[i-1][j-w[i]]),即把总重和前i个交换了一下顺序
//转化为一维：
//首先要理解两重循环：第一重是前i个物品件数，第二层是总重
//由边界条件，我们已有了物品件数为0的所有情况
//我们都前i个物品进行循环，在循环中，每个重量的最佳搭配可由上递推式确定
//由于只有一个数组，数组中存的是i-1时各重量的最佳选择
//从后往前才不会覆盖
//然后由于前i个物品是连续性变化的
//所以考虑每次固定物品数量，对总重进行递推
//此题的边界条件直接best[0][j]=0就可以,然后递推从1开始
//
//