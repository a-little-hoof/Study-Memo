#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int cnt(int a,int s)
{
	//cout<<a<<" "<<s<<endl;ע�͵������������� 
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
//����������ϣ���������һ���������Գ��ֶ��
//����ֻ�ÿ���return 1�ı߽�����������
//ԭ���ǲ������������Զ�����
//�����ϼ��˲����������⻹Ӧע��
