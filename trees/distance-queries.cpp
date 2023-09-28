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
	
	int n, q;
	cin >> n >> q;
	
	vector<int> adj[n + 1];
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<vector<int>> par (n + 1, vector<int> (LOG, 0));
	vector<int> level (n + 1);
	
	function<void(int,int)> dfs = [&] (int node, int parent) {
		par[node][0] = parent;
		level[node] = level[parent] + 1;
		for (auto child : adj[node]) {
			if (child == parent) continue;
			dfs (child, node);
		}
	};
	
	dfs(1, 0);
	
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	auto lift = [&] (int node, int k) {
		for (int j = 0; j < LOG; j++) {
			if (k & (1 << j)) {
				node = par[node][j];
			}
		}
		return node;
	};
	
	auto lca = [&] (int u, int v) {
		if (level[u] < level[v]) swap (u, v);
		if (level[u] > level[v]) u = lift (u, level[u] - level[v]);
		if (u == v) return u;
		
		for (int j = LOG - 1; j >= 0; j--) {
			if (par[u][j] != par[v][j]) {
				u = par[u][j];
				v = par[v][j];
			}
		}
		
		return par[u][0];
	};
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		
		int l = lca (u, v);
		
		int ans = level[u] + level[v] - 2 * level[l];
		cout << ans << "\n";
	}
	
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
