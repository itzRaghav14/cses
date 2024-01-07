#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

using state = pair<long long, pair<int,int>>;

void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int,int>> adj[n];
	
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		u--, v--;
		adj[u].push_back({v, wt});
	}
	
	vector<vector<int>> vis (n, vector<int> (2, 0));
	vector<vector<long long>> dist (n, vector<long long> (2, 1e18));
	multiset<state> st;
	
	dist[0][0] = 0;
	st.insert({0, {0, 0}});
	
	while(!st.empty()) {
		auto front = *st.begin();
		st.erase(st.begin());
		
		int node = front.second.first;
		int used = front.second.second;
		
		if(vis[node][used]) continue;
		vis[node][used] = 1;
		
		for (auto it : adj[node]) {
			
			int child = it.first;
			int wt = it.second;
			
			if(!vis[child][used] && dist[child][used] > dist[node][used] + wt) {
				st.erase({dist[child][used], {child, used}});
				dist[child][used] = dist[node][used] + wt;
				st.insert({dist[child][used], {child, used}});
			}
			
			if(used == 0 && !vis[child][1] && dist[child][1] > dist[node][0] + wt / 2) {
				st.erase({dist[child][1], {child, 1}});
				dist[child][1] = dist[node][0] + wt / 2;
				st.insert({dist[child][1], {child, 1}});
			}
		}
	}
	
	long long res = min(dist[n - 1][0], dist[n - 1][1]);
	
	cout << res << endl;
	
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
