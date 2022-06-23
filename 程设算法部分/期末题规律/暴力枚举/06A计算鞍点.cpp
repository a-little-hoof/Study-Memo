#include <iostream>
#include<cstring>
using namespace std;


int main()
{
    int a[6][6];
    for(int i=1;i<=5;++i)
    for(int j=1;j<=5;++j)
    cin>>a[i][j];
    int hangmax[6]={0};
    int liemin[6]={0};
    for(int i=1;i<=5;++i)
    {
    	int maxnum=0;
    	int minnum=1000000;
    	for(int j=1;j<=5;++j)
    	{
    		if(a[i][j]>maxnum)
    		{
    			maxnum=a[i][j];
    			hangmax[i]=j;
			}
			if(a[j][i]<minnum)
			{
				minnum=a[j][i];
				liemin[i]=j;
			}
		}
	}
	bool flag=1;
	for(int i=1;i<=5;++i)
	{
		if(liemin[hangmax[i]]==i)
		{
			flag=0;
			cout<<i<<" "<<hangmax[i]<<" "<<a[i][hangmax[i]]<<endl;
		}
			
	}
	if(flag)
	cout<<"not found"<<endl;

    return 0;
}