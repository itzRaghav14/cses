#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 2e5 + 5;

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
	
	vector<int> dist (n + 1, 0);
	vector<int> ans (n + 1, 0);
	
	function<void(int,int)> dfs = [&] (int node, int par) {
		dist[node] = 1;
		ans[node] = 1;
		int mx = 0;
		
		for (auto child : adj[node]) {
			if(child == par) continue;
			dfs (child, node);
			
			dist[node] = max (dist[node], dist[child] + 1);
			ans[node] = max ({ans[node], ans[child], dist[child] + mx + 1});
			
			mx = max (mx, dist[child]);
		}
	};
	
	dfs (1, 0);
	cout << ans[1] - 1 << endl;
	
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
