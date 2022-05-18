#include<iostream>
using namespace std;

void op(int n,char s,char mid,char e)
{
	if(n==1)
	{
		cout<<n<<":"<<s<<"->"<<e<<endl;
		return;
	}
	else
	{
		op(n-1,s,e,mid);
		cout<<n<<":"<<s<<"->"<<e<<endl;
		op(n-1,mid,s,e);
	}
}
int main(){
	int n;
	cin>>n;
	char a,b,c;
	cin>>a>>b>>c;
	op(n,a,b,c);
	return 0;
}
//汉诺塔 http://bailian.openjudge.cn/practice/4147/
//把一个问题分解为子问题
//调用参数 返回什么 何时结束
//
