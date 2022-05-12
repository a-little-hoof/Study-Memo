#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int a[5][5];
	int b[5][5]={0};
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			scanf("%d",&a[i][j]);
	int change[10]={0};
	int ans[10]={0};
	int minmove=400;
	for(change[1]=0;change[1]<4;++change[1])
	for(change[2]=0;change[2]<4;++change[2])
	for(change[3]=0;change[3]<4;++change[3])
	for(change[4]=0;change[4]<4;++change[4])
	for(change[5]=0;change[5]<4;++change[5])
	for(change[6]=0;change[6]<4;++change[6])
	for(change[7]=0;change[7]<4;++change[7])
	for(change[8]=0;change[8]<4;++change[8])
	for(change[9]=0;change[9]<4;++change[9])
	{
		memset(b,0,sizeof(b));
		b[1][1]=(a[1][1]+change[1]+change[2]+change[4])%4;
		b[1][2]=(a[1][2]+change[1]+change[2]+change[3]+change[5])%4;
		b[1][3]=(a[1][3]+change[2]+change[3]+change[6])%4;
		b[2][1]=(a[2][1]+change[1]+change[4]+change[5]+change[7])%4;
		b[2][2]=(a[2][2]+change[1]+change[3]+change[5]+change[7]+change[9])%4;//这里少加了一个
		b[2][3]=(a[2][3]+change[3]+change[5]+change[6]+change[9])%4;
		b[3][1]=(a[3][1]+change[4]+change[8]+change[7])%4;
		b[3][2]=(a[3][2]+change[8]+change[5]+change[7]+change[9])%4;
		b[3][3]=(a[3][3]+change[6]+change[8]+change[9])%4;
		bool flag=1;
		for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
		{
			if(b[i][j])
				flag=0;
		}
		if(flag)
		{
			int sum=0;
			for(int i=1;i<=9;++i)
				sum+=change[i];
			if(sum<minmove)
			{
				minmove=sum;
				for(int i=1;i<=9;++i)
					ans[i]=change[i];
			}
		}
	}
	for(int i=1;i<=9;++i)
	{
		while(ans[i])
		{
			cout<<i<<" ";
			ans[i]--;
		}
	}
	return 0;
}
//����-ö��-�ж�-��� 
