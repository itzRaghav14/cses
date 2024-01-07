#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int LOG = 20;

void solve() {
	
	int n;
	cin >> n;
	
	vector<int> adj[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<vector<int>> dp (n + 1, vector<int> (2, 0));
	
	function<void(int,int)> dfs = [&] (int node, int par) {
		int extra = 0;
		for (int child : adj[node]) if (child != par) {
			dfs (child, node);
			if (dp[child][0] == dp[child][1]) extra = 1;
			dp[node][0] += dp[child][1];
		}
		dp[node][1] = dp[node][0] + extra;
	};
	
	dfs (1, 0);
	
	cout << dp[1][1] << endl;
	
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
