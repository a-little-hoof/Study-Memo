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
//�жϽ��Ƿ����
 
void solve()
{
	for(int i=0;i<(1<<6);++i)
	{
		int k=i;
		for(int j=1;j<=6;++j)
		{
			ans[1][j]=k%2;
			k/=2;
			//������������һ��
			//�������ȡ���һλ 
		}
		if(check_ans())
		break;
	}
	//ö�ٵ�һ�����
	 
	//����� 
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

//Ϩ������ http://bailian.openjudge.cn/practice/2811/
//ö�� ����-ö��-�ж�-��� 
//�ҵ����⣺ 
//��һ��ö�ٿ���λ���� 
//��α��ⷨ������һ��ans������ 
//�������鿪��һЩ����Χ���ÿ��� ���������Լ�����������Ŀ��� 
//
//
