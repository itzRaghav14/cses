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
	
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<vector<long long>> dist (n, vector<long long> (n, 1e18));	
	
	auto ckmin = [&] (long long &a, long long b) {
		return a > b ? a = b, 1 : 0;
	};
	
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		ckmin(dist[u][v], w);
		ckmin(dist[v][u], w);
	}
	
	for(int i = 0; i < n; i++)
		dist[i][i] = 0;
	
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				ckmin (dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	while(q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		long long res = dist[u][v] < 1e18 ? dist[u][v] : -1;
		
		cout << res << "\n";
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
