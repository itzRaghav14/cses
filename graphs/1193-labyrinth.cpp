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
	array<int,2> src, dest;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == 'A') src = {i, j};
			if(mat[i][j] == 'B') dest = {i, j};
		}
	}
	
	vector<vector<int>> from (n, vector<int> (m, -1));
	
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	
	auto dirToChar = [&] (int idx) {
		static char dir[]= {'L', 'R', 'U', 'D'};
		return dir[idx];
	};
	
	auto isValid = [&] (int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	};
	
	auto bfs = [&] (array<int,2> src) {
		
		vector<vector<int>> vis(n, vector<int> (m, 0));
		queue<pair<int,int>> q;
		
		q.push({src[0], src[1]});
		vis[src[0]][src[1]] = 1;
		
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			
			for(int i = 0; i < 4; i++) {
				int x = row + dx[i];
				int y = col + dy[i];
				if(!isValid(x, y) || mat[x][y] == '#' || vis[x][y]) continue;
				vis[x][y] = 1;
				from[x][y] = i;
				q.push({x, y});
			}
		}
	};
	
	bfs(src);
	
	if(from[dest[0]][dest[1]] == -1) {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	
	string path = "";
	int row = dest[0], col = dest[1];
	int steps = 0;
	
	while(row != src[0] || col != src[1]) {
		if(from[row][col] == -1) break;
		steps++;
		int dir = from[row][col];
		path += dirToChar (dir);
		row -= dx[dir];
		col -= dy[dir];
	}
	
	cout << steps << endl;
	
	reverse(path.begin(), path.end());
	cout << path << endl;
	
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
