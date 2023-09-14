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
	
	vector<vector<char>> mat(n, vector<char> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	
	auto isValid = [&] (int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	};
	
	function<void(int, int)> dfs = [&] (int row, int col) {
		mat[row][col] = '#';
		for(int i = 0; i < 4; i++) {
			int x = row + dx[i];
			int y = col + dy[i];
			if(!isValid(x, y) || mat[x][y] == '#') continue;
			dfs(x, y);
		}
	};
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '.') {
				dfs(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	
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
