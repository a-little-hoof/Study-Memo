#include <iostream>
#include<cstring>
using namespace std;


int main()
{
    int T;
    cin>>T;
    while(T)
    {
    	--T;
    	char str[1010];
    	int num[1010];
    	cin>>str;
    	int len=strlen(str);
    	int cnt=0;
    	for(int i=0;i<len;++i)
    	{
    		if(str[i]=='0')
    		{
    			num[i]=0;
			}
			else
			{
				num[i]=1;
				cnt++;
			}
		}
		int mg=min(cnt,len-cnt);
		int front=0;
		for(int i=0;i<len;++i)
		{
			front+=num[i];
			mg=min(mg,front+len-i-1-cnt+front);
		}
		cout<<mg<<endl;
	}
    return 0;
}
