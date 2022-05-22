#include<iostream>
#include<cstring>
using namespace std;
int a[200][200];
int b[200][200];
int f(int i,int j)
{
	if(b[i][j])
	return b[i][j];
	b[i][j]=1;
	if(a[i][j]<a[i-1][j])
	b[i][j]=max(b[i][j],f(i-1,j)+1);
	if(a[i][j]<a[i][j-1])
	b[i][j]=max(b[i][j],f(i,j-1)+1);
	if(a[i][j]<a[i+1][j])
	b[i][j]=max(b[i][j],f(i+1,j)+1);
	if(a[i][j]<a[i][j+1])
	b[i][j]=max(b[i][j],f(i,j+1)+1);
	return b[i][j];		
}
int main(){
	int r,c;
	cin>>r>>c;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			f(i,j);
		}
	}
	int maxlen=0;
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		maxlen=max(maxlen,b[i][j]);
	}
	cout<<maxlen<<endl;

	return 0;
}

