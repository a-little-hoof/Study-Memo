#include <iostream>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char ex[200];
bool p(int s,int e)
{
//	for(int i=s;i<=e;++i)
//	cout<<ex[i];
//	cout<<endl;
	int l=0,r=0;
	for(int i=s;i<=e;++i)
	{
		if(ex[i]=='(')
		++l;
		if(ex[i]==')')
		++r;
		if(ex[i]=='|'&&l==r)
		return p(s,i-1)||p(i+1,e);
	}
	l=0;
	r=0;
	for(int i=s;i<=e;++i)
	{
		if(ex[i]=='(')
		++l;
		if(ex[i]==')')
		++r;
		if(ex[i]=='&'&&l==r)
		return p(s,i-1)&&p(i+1,e);
	}
	if(ex[s]=='(')
	return p(s+1,e-1);
	if(ex[s]=='!')
	return !p(s+1,e);
	if(ex[s]=='V')
	return 1;
	if(ex[s]=='F')
	return 0;
}
int main() {
	char s[200];
	int cnt=1;
	while(cin.getline(s,200))
	{
		int len=strlen(s);
		int len2=0;
		memset(ex,0,sizeof(ex));
		for(int i=0;i<len;++i)
		{
			if(s[i]!=' ')
			{
				ex[len2]=s[i];
				++len2;
			}
		}
		printf("Expression %d: %c\n",cnt,p(0,len2-1)==1?'V':'F');
		++cnt;
		
	}
	return 0;
}
