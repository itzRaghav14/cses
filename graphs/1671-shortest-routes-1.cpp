#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
template <typename T> using minHeap = priority_queue<T, vector<T>, greater<T>>;
 
vector<long long> dijkstra (int n, vector<pair<int,int>> adj[]) {
	
	vector<int> vis (n, 0);
	vector<long long> dist (n, 1e18);
	minHeap<pair<long long,int>> pq;
	
	pq.push({0, 0});
	dist[0] = 0;
	
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		
		if(vis[node]) continue;
		vis[node] = 1;
		
		for(auto it : adj[node]) {
			int child = it.first;
			int wt = it.second;
			long long newDist = dist[node] + wt;
			if(vis[child]) continue;
			if(dist[child] <= newDist) continue;
			dist[child] = newDist;
			pq.push({newDist, child});
		}
	}
	
	return dist;
	
}
 
void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int,int>> adj[n];
	
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
	}
	
	vector<long long> dist = dijkstra(n, adj);
	
	for(int i = 0; i < n; i++) {
		cout << dist[i] << " \n"[i == n - 1];
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
