#include<iostream>
#include<cstring>
using namespace std;

int cnt(int m,int n)
{
	if(m==0)
	return 1;
	if(n==0)
	return 0;
	if(m<n)
	return cnt(m,m);
	if(m>=n)
	return cnt(m,n-1)+cnt(m-n,n);
}
int main(){
	int t;
	cin>>t;
	while(t)
	{
		t--;
		int m,n;
		cin>>m>>n;
		cout<<cnt(m,n)<<endl;
	}
	
	return 0;
}
