#include<iostream>
#include<cstring>
using namespace std;

int cnt(int n)
{
	if(n==0)
	return 1;
	if(n<0)
	return 0;
	return cnt(n-1)+cnt(n-2);
}
int main(){
	int n;
	while(cin>>n)
	{
		cout<<cnt(n)<<endl;
	}
	
	return 0;
}
