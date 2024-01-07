
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
void solve() {
	
 	int n, m;
	cin >> n >> m;
	
	int dp[n + 1][m + 1];
	fill_n(&dp[0][0], n * m + n + m + 1, n * m);
	debug(dp, (int*)dp, n + 1, m + 1);
	
	auto setMin = [&] (int &a, int b) {
		return a > b ? a = b, 1 : 0;
	};
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			
			if(i == j) {
				dp[i][j] = 0;
				continue;
			}
			
			for(int k = 1; k < i; k++) {
				setMin(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
			}
			
			for(int k = 1; k < j; k++) {
				setMin(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
			}
		}
		debug(current dp, dp[i], m + 1);
	}
	
	cout << dp[n][m] << endl;
	
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
