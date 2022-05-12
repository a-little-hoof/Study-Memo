#include <iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100010];
bool flag=1;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	int m;
	cin>>m;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		int p=m-a[i];
		if(p<0||flag==0)
		{
			break;
		}
		int s=i+1;
		int e=n;
		while(s<=e)//是<=否则1 2 4 5，和为6找出来2 4
		{
			int mid=s+(e-s)/2;
			if(a[mid]==p)
			{
				cout<<a[i]<<" "<<p<<endl;
				flag=0;
				break;//记得要有break
			}
			if(a[mid]<p)
			{
				s=mid+1;
			}
			if(a[mid]>p)
				e=mid-1;
		}
	}
	if(flag)
	cout<<"No"<<endl; 
	return 0;
}

//二分查找http://bailian.openjudge.cn/practice/4143/
//先排序，然后二分查找