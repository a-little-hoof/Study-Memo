#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
using namespace std;

bool exist[110][110]={0};
int A,B,C;
const string op[7]={"1\n","FILL(1)\n","FILL(2)\n","POUR(1,2)\n","POUR(2,1)\n","DROP(1)\n","DROP(2)\n"};
struct sit{
	int a;
	int b;
	int pre;
	int type;
	sit(int _a,int _b,int _pre,int _type):a(_a),b(_b),pre(_pre),type(_type){};
	sit(){};
	sit(const sit & tmp){
		a=tmp.a;
		b=tmp.b;
		pre=tmp.pre;
		type=tmp.type;
	}
};
int main()
{
	cin>>A>>B>>C;
	int s=1,e=1;
	sit que[120000]; 
	que[1]=sit(0,0,0,0);
	exist[0][0]=1;
	s=1;
	e=2;
	while(s!=e)
	{
		if(que[s].a==C ||que[s].b==C)
		break;
		else
		{
			if(exist[A][que[s].b]==0)
			{
				que[e]=sit(A,que[s].b,s,1);
				exist[A][que[s].b]=1;
				++e;
			}
			if(exist[que[s].a][B]==0)
			{
				que[e]=sit(que[s].a,B,s,2);
				exist[que[s].a][B]=1;
				++e;
			}
			if(exist[max(que[s].a-(B-que[s].b),0)][min(que[s].b+que[s].a,B)]==0)
			{
				que[e]=sit(max(que[s].a-(B-que[s].b),0),min(que[s].b+que[s].a,B),s,3);
				exist[max(que[s].a-(B-que[s].b),0)][min(que[s].b+que[s].a,B)]=1;
				++e;
			}//pour(1,2)
			if(exist[min(A,que[s].a+que[s].b)][max(que[s].b-(A-que[s].a),0)]==0)
			{
				que[e]=sit(min(A,que[s].a+que[s].b),max(que[s].b-(A-que[s].a),0),s,4);
				exist[min(A,que[s].a+que[s].b)][max(que[s].b-(A-que[s].a),0)]=1;
				++e;
			}//pour(2,1)
			if(exist[0][que[s].b]==0)
			{
				que[e]=sit(0,que[s].b,s,5);
				exist[0][que[s].b]=1;
				++e;
			}
			if(exist[que[s].a][0]==0)
			{
				que[e]=sit(que[s].a,0,s,6);
				exist[que[s].a][0]=1;
				++e;
			}
			++s;	
		} 
	}
	if(s==e)
		printf("impossible\n");
	else
	{
		int ans[10000];
		int num=0;
		while(que[s].type!=0)
		{
			++num;
			ans[num]=que[s].type;
			s=que[s].pre;
		}
		cout<<num<<endl;
		for(int i=num;i>0;--i)
			cout<<op[ans[i]];
	}
	//cout<<que[1].a;
    return 0;
}
