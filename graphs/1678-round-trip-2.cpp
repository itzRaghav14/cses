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
	
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(u == v) continue;
		adj[u].push_back(v);
	}
	
	vector<int> vis (n, 0);
	vector<int> path (n, 0);
	vector<int> par (n, -1);
	
	function<int(int, int)> dfs = [&] (int node, int parent) {
		par[node] = parent;
		
		if(path[node]) return node;
		if(vis[node]) return -1;
		
		path[node] = 1;
		vis[node] = 1;
		
		for (auto child : adj[node]) {
			int res = dfs(child, node);
			if(res != -1) {
				return res;
			}
		}
		
		path[node] = 0;
		return -1;
		
	};
	
	vector<int> cycle;
	
	auto getCycle = [&] (int src) -> vector<int> {
		vector<int> cycle;
		int node = src;
		while(node != -1) {
			int parent = par[node];
			cycle.push_back(node);
			par[node] = -1;
			node = parent;
		}
		reverse(cycle.begin(), cycle.end());
		return cycle;
	};
	
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int res = dfs(i, -1);
			if(res != -1) {
				cycle = getCycle(res);
				break;
			}
		}
	}
	
	if(cycle.empty()) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	cout << cycle.size() << endl;
	for(auto it : cycle) {
		cout << it + 1 << " ";
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
