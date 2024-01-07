#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int LOG = 20;

void solve() {
	
	int n, q;
	cin >> n >> q;
	
	vector<vector<int>> par (n + 1, vector<int> (LOG, 0));
	for (int i = 2; i <= n; i++) {
		cin >> par[i][0];
	}
	
	auto lift = [&] (int node, int k) {
		for (int j = 0; j < LOG; j++) {
			int bit = 1 << j;
			if (k & bit) {
				node = par[node][j];
			}
		}
		return node;
	};
	
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	while (q--) {
		int node, k;
		cin >> node >> k;
		int anc = lift (node, k);
		cout << (anc > 0 ? anc : -1) << endl;
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
