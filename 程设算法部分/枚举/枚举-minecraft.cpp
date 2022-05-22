#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;



int main(){
	int n;
	cin>>n;
	int p=pow(n,0.5);
	int minnum=1000000000;
	//cout<<p<<endl;
	for(int i=1;i<=p;++i)
	{
		for(int j=i;j<=p;++j)
		{
			for(int k=j;k<=n;++k)
			{
				if(k*j*i==n)
				{
					minnum=min(minnum,2*(k*i+k*j+i*j));
				}
			}
		}
	}
	cout<<minnum<<endl;
	return 0;
}

// http://noi.openjudge.cn/ch0201/7216/
//注意枚举的范围，找不到bug就用小数据试试
//k必须到n，但ij不用