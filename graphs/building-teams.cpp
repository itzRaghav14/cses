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
 
const int N = 1e5 + 10;
 
void dfs(int node, vector<int> adj[], vector<int> &ans) {
	
	for(auto child : adj[node]) {
		if(!ans[child]) {
			ans[child] |= (ans[node] ^ 3);
		debug(dfs, node, child, ans[node], ans[child]);
			dfs(child, adj, ans);
		} else {
			ans[child] |= (ans[node] ^ 3);
		debug(dfs, node, child, ans[node], ans[child]);
			
		}
	}
	
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
	
	dbg(adj, n);
	
	vector<int> ans(n);
	
	for(int i = 0; i < n; i++) {
		
		if(!ans[i]) {
			ans[i] = 1;
			dfs(i, adj, ans);
		}
	}
	
	dbg(ans);
	
	for(int i = 0; i < n; i++) {
		if(ans[i] == 3) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
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
