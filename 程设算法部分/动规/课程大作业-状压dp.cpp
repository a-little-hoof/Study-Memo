#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
using namespace std;

int dp[1<<15]; //当前这些课程中最优的排序方式 
string course[20];
int t[20];      //完成所需时间
int d[20];      //截止时间
int sum[1<<15];
string out[1<<15];

 
int main()
{
    int T,n,i,j;
    cin>>T;
    while(T)
    {
    	--T;
        cin>>n;
        for(i=0;i<n;++i)
        {
            cin>>course[i]>>d[i]>>t[i];
            sum[1<<i]=t[i];
        }
        int num=1<<n;
        for(i=1;i<num;++i)
            for(j=0;j<n;++j)
                if(i&(1<<j))
                {
                    sum[i]=sum[i-(1<<j)]+t[j];//记录该状态总用时 动规1 
                }
        dp[0]=0;//此状态最少罚时 
        for(i=0;i<num;++i)
            out[i]="";
        for(i=1;i<num;++i)
        {
            for(j=0;j<n;++j)//挨个寻找把谁放最后的最优方式 
            {
            	int p=1<<j;
            	if(i&p)
            	{
            		if(out[i]=="")
            		{
            			out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);
					}//如果为空 
            		else if(dp[i-(1<<j)]+max(0,sum[i]-d[j])<dp[i])
            		{
            			out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);
					}//如果罚分更少 
					else if(dp[i-(1<<j)]+max(0,sum[i]-d[j])==dp[i]&&out[i-p]+course[j]+"\n"<out[i])
					{
						out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);//之前的最优排序方式加上j 
					}//如果字典序更小 
					
				}
                
            }
        }
        cout<<dp[num-1]<<endl;
        cout<<out[num-1];
    }
    return 0;
}
