#include <iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int n,l[100005],c;

bool check(int x)
{
	int count=1;
	int temp=l[0];
	for(int i=1;i<n;++i)
	{
		if(l[i]-temp>=x)
		{
			count++;
			temp=l[i];
			if(count>=c)
			return 1;
		}
	}
	return 0;
}
int binary_search()
{
	int le=0,ri=l[n-1]-l[0];
	int ans=0;
	while(le<=ri)
	{
		int mid=le+(ri-le)/2;
		if(check(mid))
		{
			ans=mid;
			le=mid+1;
		}
		else
		{
			ri=mid-1;
		}
	}
	return ans;
	//别忘了return
}
int main() {
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		for(int i=0;i<n;++i)
		cin>>l[i];
		sort(l,l+n);
		cout<<binary_search()<<endl;
	}
	return 0;
}
//疯牛http://bailian.openjudge.cn/practice/2456/
//贪心+二分查找
//二分查找枚举距离
//然后判断距离可不可行，贪心，有点像魔王的军队
//int型函数记得要有return