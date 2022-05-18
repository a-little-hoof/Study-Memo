#include<iostream>
#include<cstring>
using namespace std;

int cnt(int n)
{
	int num=0;
	if(n==0)
	return 1;
	for(int i=1;i<=2;i++)
	{
		if(n<i)
		continue;
		num+=cnt(n-i); 
		
	}
	return num;
}
int main(){
	int n;
	while(cin>>n)
	{
		cout<<cnt(n)<<endl;
	}
	
	return 0;
}
//http://bailian.openjudge.cn/practice/4017/
//将递归问题分解为规模更小的子问题求解