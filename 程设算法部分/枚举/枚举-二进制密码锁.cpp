#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main(){
	char n[35];
	char s[35];
	memset(n,0,sizeof(n));
	memset(s,0,sizeof(s));
	cin>>n>>s;
	int len=strlen(n);
	int change[len+1]={0};
	int minmove=100;
	int now[35]={0};
	for(int i=1;i<=len;i++)
	{
		now[i]=abs(((n[i-1]-'0')-(s[i-1]-'0')))%2;
	}
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			change[1]=i;
			change[2]=j;
			if((now[1]+i+j)%2!=0)//这里
			continue;
			for(int k=3;k<=len;k++)
			{
				change[k]=(now[k-1]+change[k-1]+change[k-2])%2;
			}
			if((now[len]+change[len-1]+change[len])%2==0)
			{
				int cnt=0;
				for(int k=1;k<=len;k++)
				cnt+=change[k];
				if(cnt<minmove)
				minmove=cnt;
			}
		}
	}
	if(minmove==100)
	cout<<"impossible"<<endl;
	else
	cout<<minmove<<endl;
	 
	
	return 0;
}
//输入-枚举-判断-输出
//第一次错是因为数组从谁开始没搞清：0，1
//第二次错是最后一位可收到自己以及前一位的影响
//第三次错是因为枚举i，j时没有考虑第一位成不成立，如果不成立要直接跳过
//