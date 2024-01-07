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
 
void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> g[n + 1];
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	queue<int> q;
	vector<int> dist(n + 1, N);
	vector<int> from(n + 1, -1);
	
	dist[1] = 0;
	q.push(1);
	
	while(!q.empty()) {
		
		int node = q.front();
		q.pop();
		
		for(auto child : g[node]) {
			if(dist[child] <= dist[node] + 1) continue;
			dist[child] = dist[node] + 1;
			from[child] = node;
			q.push(child);
		}
	}
	
	if(dist[n] == N) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	cout << dist[n] + 1 << endl;
	
	vector<int> ans = {n};
	int node = n;
	
	while(from[node] != -1) {
		node = from[node];
		ans.push_back(node);
	}
	
	reverse(ans.begin(), ans.end());
	for(auto it : ans) {
		cout << it << " ";
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
