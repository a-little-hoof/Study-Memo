#include <iostream>
#include<cstring>
#include<queue>
using namespace std;


int main()
{
    int T;
    cin>>T;
    while(T)
    {
    	--T;
    	int n;
    	cin>>n;
    	int x[55];
    	int y[55];
    	int tmpa,tmpb;
    	int number=0;
    	for(int i=1;i<=n;++i)
    	{
    		cin>>tmpa>>tmpb;
    		bool flag=1;
    		for(int j=1;j<=number;++j)
    		{
    			if(x[j]==tmpa&&y[j]==tmpb)
    			{
    				flag=0;
				}
			}
			if(flag)
			{
				number++;
				x[number]=tmpa;
				y[number]=tmpb;
			}
		}
		int cnt=0;
		for(int i=1;i<=number;++i)
		{
			for(int j=i+1;j<=number;++j)
			{
				for(int k=j+1;k<=number;k++)
				{
					for(int l=k+1;l<=number;l++)
					{
						if(x[i]==x[j])
						{
							if(x[k]==x[l])
							{
								if(y[i]==y[k]&&y[j]==y[l])
								++cnt;
								if(y[i]==y[l]&&y[j]==y[k])
								++cnt;
							}
						}
						if(x[i]==x[k])
						{
							if(x[j]==x[l])
							{
								if(y[i]==y[j]&&y[k]==y[l])
								++cnt;
								if(y[i]==y[l]&&y[j]==y[k])
								++cnt;
							}
						}
						if(x[i]==x[l])
						{
							if(x[k]==x[j])
							{
								if(y[i]==y[k]&&y[j]==y[l])
								++cnt;
								if(y[i]==y[j]&&y[l]==y[k])
								++cnt;
							}
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}

    return 0;
}