#include <iostream>
using namespace std;
int dp[110][13] = {};//level;eggs最坏情况下的最少次数

int main()
{
    int n, m;
    for(int i = 0;i <= 101; i++)
        for(int j = 1; j <= 11;j++)
            dp[i][j] = i;
	for(int j = 1; j<= 101;j++)
   		for(int i = 2;i <= 11 ;i++)
        	for(int k = 1;k <= j; k++)
            	dp[j][i] = min(dp[j][i],max(dp[k-1][i-1],dp[j-k][i])+1);//碎了没碎两种情况，这里取更坏情况
    while(cin >> n >> m)
	{
        cout << dp[n][m] << endl;
    }
    return 0;
}