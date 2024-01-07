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
	
	vector<multiset<int>> dist (n + 1);
	vector<int> ans (n + 1, 0);
	
	function<void(int,int)> dfs1 = [&] (int node, int par) {
		dist[node].insert(1);
		for (auto child : adj[node]) {
			if (child == par) continue;
			dfs1 (child, node);
			dist[node].insert(*dist[child].rbegin() + 1);
		}
	};
	
	auto change = [&] (int node, int child) {
		dist[node].erase(dist[node].find(*dist[child].rbegin() + 1));
		dist[child].insert(*dist[node].rbegin() + 1);
	};
	
	function<void(int,int)> dfs2 = [&] (int node, int par) {
		ans[node] = *dist[node].rbegin();
		for (auto child : adj[node]) {
			if (child == par) continue;
			change (node, child);
			dfs2 (child, node);
			change (child, node);
		}
	};
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] - 1 << " ";
	} cout << endl;
	
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
