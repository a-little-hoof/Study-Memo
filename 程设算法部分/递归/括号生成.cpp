#include <iostream>
#include<cstring>
using namespace std;

char ans[30];
int n;
void sheng(int le,int ri,int pos)
{
	if(le==0&&ri==0)
	{
		for(int i=1;i<=2*n;++i)
		cout<<ans[i];
		cout<<endl;
		return;
	}
	if(le)
	{
		ans[pos]='(';
		sheng(le-1,ri,pos+1);
		ans[pos]=0;
	}
	if(ri&&ri>le)
	{
		ans[pos]=')';
		sheng(le,ri-1,pos+1);
		ans[pos]=0;
	}
}
int main()
{
    cin>>n;
    memset(ans,0,sizeof(ans));
    sheng(n,n,1);

    return 0;
}

//http://cxsjsx.openjudge.cn/practise2022algo/07D/
//回溯
//但是要注意 放括号时必须保证剩余左括号数目小于右括号
//即已放置的左括号数目要大于右括号
//