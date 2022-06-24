#include <iostream>
using namespace std;
const int MAXN = 18;
int used[MAXN];
int W;
int m, n, ans = (1 << 30);
int item[MAXN];
int bag[MAXN];
void dfs(int x, int sum) {
	if (sum >= ans) return;//x物品 sum背包数
	if (x == n) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < sum; ++i) {
		if (bag[i] >= item[x]) {
			bag[i] -= item[x];
			dfs(x + 1, sum);
			bag[i] += item[x];
		}
	}
	bag[sum] -= item[x];
	dfs(x + 1, sum + 1);
	bag[sum] += item[x];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> item[i];
		bag[i] = m;
	}
	dfs (0, 1);
	cout << ans << endl;
	return 0;
}