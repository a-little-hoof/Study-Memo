#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int cnt(int a,int s)
{
	//cout<<a<<" "<<s<<endl;注释掉啊啊啊啊啊啊 
	if(a==1)
	return 1;
	int num=0;
	for(int i=s;i<=a;++i)
	{
		if(a%i==0)
			num+=cnt(a/i,i);
	}
	return num;
}

int main(){
	int n;
	cin>>n;
	while(n)
	{
		--n;
		int a;
		cin>>a;
		cout<<cnt(a,2)<<endl;
	}
	return 0;
}
//http://cxsjsx.openjudge.cn/practise2022algo/01D/
//类似数字组合，但问题是一个因数可以出现多次
//这里只用考虑return 1的边界条件就行了
//原因是不管怎样都会自动返回
//考场上极端不熟练，此题还应注意
