#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
char grid[730][730];
void op(int i,int j,int n)
{
	if(n==1)
	{
		grid[i][j]='X';
		return;
	}
	int num=pow(3,n-2);
	op(i,j,n-1);
	op(i-num,j-num,n-1);
	op(i-num,j+num,n-1);
	op(i+num,j-num,n-1);
	op(i+num,j+num,n-1);
}
int main()
{
 	int n;
 	while(cin>>n)
	{
		if(n==-1)
		break;
		if(n==1)
		cout<<"X"<<endl;
		else
		{
			int num=pow(3,n-2);
			num=num+num/2+1;
			op(num,num,n);
			int stop=pow(3,n-1);
			for(int i=1;i<=stop;++i)
			{
				for(int j=1;j<=stop;++j)
				{
					if(grid[i][j]=='X')
					cout<<'X';
					else
					cout<<" ";
				}
				cout<<endl;
			}
		}
		cout<<"-"<<endl;
	}    
    return 0;
}
