#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 2e5 + 5;

int n;
int par[N];

int ans[N], sizes[N];
vector<int> adj[N];

void dfs (int node) {
	int size = 1;
	
	for (int child : adj[node]) {
		if (child == par[node]) continue;
		dfs(child);
		
		size += sizes[child];
	}
	
	sizes[node] = size;
	
	ans[node] = sizes[node] - 1;
}

void solve() {
	
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
	}
	
	dfs(1);
	
	for (int node = 1; node <= n; node++) {
		cout << ans[node] << " ";
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
