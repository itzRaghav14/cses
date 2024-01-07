
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
	
	int n;
	cin >> n;
	
	vector<vector<int>> a(n, vector<int> (3, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	
	sort(a.begin(), a.end());
	
	vector<long long> dp (n + 1, 0);
	
	auto ckmax = [&] (long long &a, long long b) {
		return a < b ? a = b, 1 : 0;
	};
	
	for(int i = 0; i < n; i++) {
		
		// notPick
		ckmax(dp[i + 1], dp[i]);
		
		// pick
		auto it  = lower_bound(a.begin(), a.end(), a[i][1], [] (vector<int> &v, long long tar) {
			return v[0] <= tar;
		});
		
		int next = it - a.begin();
		ckmax(dp[next], dp[i] + a[i][2]);
		
	}
	
	cout << dp[n] << endl;
	
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
