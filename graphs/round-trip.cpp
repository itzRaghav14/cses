#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
// #define endl "\n"
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ;
#define crndl ;
#endif
 
template <class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
 
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { out << "[ "; for (const auto &x : v) out << x << ' '; out << "] "; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
 
int dfs(int node, int par, vector<int> &vis, vector<int> &from, vector<int> adj[]) {
	
	from[node] = par;
	
	if(vis[node]) {
		return node;
	}
	
	vis[node] = 1;
	
	for(auto child : adj[node]) {
		if(child == par) continue;
		int res = dfs(child, node, vis, from, adj);
		if(res != -1) return res;
	}
	
	return -1;
	
}
 
void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n];
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	debug(graph, adj, n);
	
	vector<int> vis(n), from(n, -1);
	int res = -1;
	
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		res = dfs(i, -1, vis, from, adj);
		if(res != -1) break;
	}
	
	dbg(vis);
	dbg(from);
	
	if(res == -1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	vector<int> ans = {res};
	int node = from[res];
	
	while(node != res) {
		ans.push_back(node);
		node = from[node];
	}
	
	ans.push_back(res);
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(auto it : ans) {
		cout << it + 1 << " ";
	} cout << endl;
	
}
 
int main() {
	
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
