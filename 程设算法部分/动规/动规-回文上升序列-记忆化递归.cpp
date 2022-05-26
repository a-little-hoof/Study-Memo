#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long cnt[255][255];
int find(int a,int i)
{
	if(cnt[a][i]!=0)
	return cnt[a][i];
	if(a==0)
	return 1;
	if(i==0)
	return 0;
	if(a<i)
	return find(a,a);
	if(a>=i)
	return find(a-i,i)+find(a,i-1);
	return 0;
	
}//��Ϊa�����Ϊi
int main(){
	memset(cnt,0,sizeof(cnt));
	int n;
	for(int i=1;i<255;++i)
	for(int j=1;j<255;++j)
	cnt[i][j]=find(i,j); 
	while(cin>>n)
	{
		if(n==0)
		break;
		long long to=0;
		for(int i=1;i<=n;++i)
		{
			if((n-i)%2==0)
			to+=find((n-i)/2,i);//��iд��1 
			//�м�����i�����ߵ����з�ʽ
		}
		if(n%2==0)
		to+=find(n/2,n/2);
		cout<<n<<" "<<to<<endl;
	}
	return 0;
}
//http://cxsjsx.openjudge.cn/hw202215/A/
//1���ؼ����ڣ���������Ҳ����ڼ�������
//���ɴ�С������
//2�����������¼һ�ߵݹ�����ʡʱ��
//���ּ��仯�ݹ�
//
//
//