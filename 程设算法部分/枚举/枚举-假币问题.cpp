#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

char lef[3][10],righ[3][10],result[3][10];
int status[12];

bool balanced(){
	int i,k,leftw,rightw;
	for(i=0;i<3;i++)
	{
		leftw=rightw=0;
		for(k=0;k<6&&lef[i][k]!=0;k++)
		{
			leftw+=status[lef[i][k]-'A'];
			rightw+=status[righ[i][k]-'A'];
			
		}
		if(leftw>rightw&&result[i][0]!='u')
		return 0;
		if(leftw==rightw&&result[i][0]!='e')
		return 0;
		if(leftw<rightw&&result[i][0]!='d')
		return 0;
	}
	return 1;
}
int main() {
	int i,num;
	scanf("%d",&num);
	while(num)
	{
		num--;
		for(i=0;i<3;i++)
			scanf("%s%s%s",lef[i],righ[i],result[i]);
		memset(status,0,sizeof(status));
		for(i=0;i<12;i++)
		{
			status[i]=1;
			if(balanced())
			break;
			status[i]=-1;
			if(balanced())
			break;
			status[i]=0;
		}
		printf("%c is the counterfeit coin and it is %s",i+'A',status[i]>0?"heavy\n":"light");
	}
	return 0;
}

//假币问题http://bailian.openjudge.cn/practice/2692/
//枚举法
//思路：读入-枚举结构-判断是否符合题意-输出
//注意读题，没说每次天平两端放几枚
//注意最后输出，加没加\n,有没有句号
//值得学习的部分：bool函数让结构更清晰
//最后输出？：可以避免if判断
