#include<iostream>
#include<cstring>
#include<algorithm> 
#include<string>
using namespace std;

int dp[1<<15]; //��ǰ��Щ�γ������ŵ�����ʽ 
string course[20];
int t[20];      //�������ʱ��
int d[20];      //��ֹʱ��
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
                    sum[i]=sum[i-(1<<j)]+t[j];//��¼��״̬����ʱ ����1 
                }
        dp[0]=0;//��״̬���ٷ�ʱ 
        for(i=0;i<num;++i)
            out[i]="";
        for(i=1;i<num;++i)
        {
            for(j=0;j<n;++j)//����Ѱ�Ұ�˭���������ŷ�ʽ 
            {
            	int p=1<<j;
            	if(i&p)
            	{
            		if(out[i]=="")
            		{
            			out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);
					}//���Ϊ�� 
            		else if(dp[i-(1<<j)]+max(0,sum[i]-d[j])<dp[i])
            		{
            			out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);
					}//������ָ��� 
					else if(dp[i-(1<<j)]+max(0,sum[i]-d[j])==dp[i]&&out[i-p]+course[j]+"\n"<out[i])
					{
						out[i]=out[i-p]+course[j]+"\n";
            			dp[i]=dp[i-p]+max(0,sum[i]-d[j]);//֮ǰ����������ʽ����j 
					}//����ֵ����С 
					
				}
                
            }
        }
        cout<<dp[num-1]<<endl;
        cout<<out[num-1];
    }
    return 0;
}
