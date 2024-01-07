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
	
	vector<int> adj[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> sz (n + 1, 0);
	
	function<void(int,int)> dfs = [&] (int node, int par) {
		sz[node] = 1;
		for (int child : adj[node]) if (child != par) {
			dfs (child, node);
			sz[node] += sz[child];
		}
	};
	dfs(1, 0);
	
	int ans = 0;
	
	auto change = [&] (int node, int child) {
		sz[node] -= sz[child];
		sz[child] += sz[node];
	};
	
	function<void(int,int)> reroot = [&] (int node, int par) {
		int mx = 0;
		for (int child : adj[node]) {
			mx = max (mx, sz[child]);
		}
		if (mx <= n / 2) {
			ans = node;
		}
		
		if (ans != 0) return;
		
		for (int child : adj[node]) if (child != par) {
			change (node, child);
			reroot (child, node);
			change (child, node);
		}
	};
	reroot(1, 0);
	
	cout << ans << endl;
	
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
