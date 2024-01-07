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
	
	vector<pair<int,int>> edges;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.push_back({u, v});
		adj[u].push_back(v);
	}
	
	vector<int> topo;
	vector<int> vis(n, 0);
	
	function<void(int)> dfs = [&] (int node) {
		if(vis[node]) return;
		vis[node] = 1;
		for (auto child : adj[node]) {
			dfs(child);
		}
		topo.push_back(node);
	};
	
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	
	auto hasCycle = [&] () {
		
		vector<int> idx (n, -1);
		
		for(int i = 0; i < n; i++) {
			idx[topo[i]] = i;
		}
		
		for (int i = 0; i < m; i++) {
			int u = edges[i].first, v = edges[i].second;
			if(idx[u] >= idx[v]) {
				return true;
			}
		}
		
		return false;
		
	};
	
	if(hasCycle()) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		cout << topo[i] + 1 << " \n"[i == n - 1];
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
