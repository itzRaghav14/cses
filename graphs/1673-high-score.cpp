#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

using edge = array<int, 3>;

void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<edge> edges (m);
	
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges[i] = {u, v, w};
	}
	
	vector<long long> dist (n, -1e15);
	dist[0] = 0;
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			int u = edges[j][0], v = edges[j][1], w = edges[j][2];
			if(dist[v] < dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}
	
	dbg(dist);
	
	vector<int> badNodes (n, 0);
	
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < m; i++) {
			int u = edges[i][0], v = edges[i][1], w = edges[i][2];
			if(dist[v] < dist[u] + w) {
				dist[v] = dist[u] + w;
				badNodes[v] = 1;
			}
		}
	}
	
	dbg(badNodes);
	
	auto getReachableNodes = [&] () -> vector<int> {
		
		vector<pair<int,int>> adjT[n];
		
		for(int i = 0; i < m; i++) {
			int u = edges[i][0], v = edges[i][1], w = edges[i][2];
			adjT[v].push_back({u, w});
		}
		
		vector<int> reachable(n, -1);
		reachable[0] = 1;
		
		function<bool(int)> dfs = [&] (int node) -> bool {
			
			if(reachable[node] != -1) {
				return reachable[node];
			}
			
			int &res = reachable[node];
			res = 0;
			
			for(auto it : adjT[node]) {
				int child = it.first;
				res |= dfs(child);
			}
			
			return res;
			
		};
		
		dfs(n - 1);
		
		return reachable;
		
	};
	
	vector<int> reachableNodes = getReachableNodes ();
	
	dbg(reachableNodes);
	
	for(int i = 0; i < n; i++) {
		if(badNodes[i] && reachableNodes[i] == 1) {
			cout << -1 << endl;
			return;
		}
	}
	
	cout << dist[n - 1] << endl;
	
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
