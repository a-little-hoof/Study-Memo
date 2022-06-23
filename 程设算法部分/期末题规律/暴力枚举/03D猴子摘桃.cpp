#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
	int honey;
	int p[105],b[105];
	while(cin>>honey)
	{
		if(honey==-1)
		break;
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
		int peach,bee;
		int cnt=0;
		while(cin>>peach>>bee)
		{
			if(peach==-1)
			break;
			++cnt;
			p[cnt]=peach;
			b[cnt]=bee;
		}
		int maxp=0;
		for(int i=1;i<=cnt;i++)
		{
			int bnumber=0;
			int pnumber=0;
			int s=i;
			while(s<=cnt&&bnumber+b[s]<=honey)
			{
				bnumber+=b[s];
				pnumber+=p[s];
				++s;
			}
			maxp=max(maxp,pnumber);
		}
		cout<<maxp<<endl;
	 } 
	return 0;
}
