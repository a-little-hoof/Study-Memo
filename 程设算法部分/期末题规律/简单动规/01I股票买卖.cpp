#include <iostream>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int pri[100001] = {};
        
        for(int i = 0; i < n; ++i){
            scanf("%d", &pri[i]);
        }
        int imin = pri[0], imax = pri[n-1];
        int dp[100001][2] = {};
        dp[0][0] = 0;
        dp[n-1][1] = 0;
        for(int i = 1; i < n; ++i){
          	imin = min(imin, pri[i]);
            dp[i][0] = max(dp[i-1][0], pri[i] - imin);
        }
        int ans = 0;
        for(int i = n-2; i >= 0; --i){
        	imax = max(imax, pri[i]);
            dp[i][1] = max(dp[i+1][1], imax - pri[i]);
            ans = max(ans, dp[i][0] + dp[i][1]);
        }
        cout << ans << endl;
    }
    return 0;
}
//以第一次卖出时间为分界线