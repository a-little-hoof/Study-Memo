#include<bits/stdc++.h>

using namespace std;
const int maxn = 10000 + 5;
int a[maxn], b[maxn],c[maxn],dp[maxn][4];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dp[0][0] = a[0];//None
	dp[0][1] = -1;//left
	dp[0][2] = b[0];//right
	dp[0][3] = -1;//both
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][3], dp[i - 1][2]) + a[i];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + b[i];
		dp[i][2] = max(dp[i - 1][3], dp[i - 1][2]) + b[i];
		dp[i][3] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
	}
	cout << max(dp[n-1][0], dp[n-1][1]);
	return 0;
}
