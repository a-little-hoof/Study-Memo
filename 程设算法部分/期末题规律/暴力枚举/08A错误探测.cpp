#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
#include<queue>
using namespace std;

int n;
int a[105][105];
bool h[105];
bool l[105];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		cin>>a[i][j];
	}
	int total=0;
	int markh=0;
	int markl=0;
	for(int i=1;i<=n;i++)
	{
		int sumh=0;
		int suml=0;
		for(int j=1;j<=n;++j)
		{
			sumh+=a[i][j];
			suml+=a[j][i];
		}
		h[i]=sumh%2;
		l[i]=suml%2;
		if(h[i])
		markh=i;
		if(l[i])
		markl=i;
		total+=(h[i]+l[i]);
	}
	if(total==0)
	cout<<"OK"<<endl;
	else if(total==2&&markh&&markl)
	cout<<markh<<" "<<markl<<endl; 
	else
	cout<<"Corrupt"<<endl;
    return 0;
}