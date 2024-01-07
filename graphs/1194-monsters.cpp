#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

using coord = array<int, 2>;

void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> mat (n, vector<char> (m, '.'));
	coord src;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == 'A') {
				src = {i, j};
			}
		}
	}
	
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	char symbol[4] = {'L', 'R', 'U', 'D'};
	
	auto isValid = [&] (int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	};
	
	auto getDist = [&] (char start) {
		vector<vector<int>> dist (n, vector<int> (m, -1));
		queue<coord> q;
		
		auto canGo = [&] (int row, int col, int x, int y) {
			if (!isValid(x, y)) return false;
			if (mat[x][y] == '#') return false;
			if (dist[x][y] != -1) return false;
			return true;
		};
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'M') {
					dist[i][j] = 0;
					q.push({i, j});
				}
				if (mat[i][j] == '#') {
					dist[i][j] = 0;
				}
			}
		}
		
		while (!q.empty()) {
			int row = q.front()[0];
			int col = q.front()[1];
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				int x = row + dx[i];
				int y = col + dy[i];
				if(!canGo (row, col, x, y)) continue;
				int newDist = dist[row][col] + 1;
				dist[x][y] = newDist;
				q.push({x, y});
			}
		}
		
		return dist;
	};
	
	vector<vector<int>> distM = getDist('M');
	
	auto bfs = [&] (coord src) -> string {
		vector<vector<int>> dist (n, vector<int> (m, -1));
		vector<vector<int>> from (n, vector<int> (m, -1));
		queue<coord> q;
		coord dest = {-1, -1};
		
		auto isDestination = [&] (int row, int col) {
			return row == 0 || col == 0 || row == n - 1 || col == m - 1;
		};
		
		auto canGo = [&] (int row, int col, int x, int y) {
			if (!isValid (x, y)) return false;
			if (mat[x][y] == '#') return false;
			if (dist[x][y] != -1) return false;
			if (distM[x][y] != -1 && dist[row][col] + 1 >= distM[x][y]) return false;
			return true;
		};
		
		dist[src[0]][src[1]] = 0;
		q.push({src[0], src[1]});
		
		while (!q.empty()) {
			int row = q.front()[0];
			int col = q.front()[1];
			q.pop();
			
			if(isDestination(row, col)) {
				dest = {row, col};
				break;
			}
			
			for (int i = 0; i < 4; i++) {
				int x = row + dx[i];
				int y = col + dy[i];
				if(!canGo(row, col, x, y)) continue;
				q.push({x, y});
				dist[x][y] = dist[row][col] + 1;
				from[x][y] = i;
			}
		}
		
		if(dest == coord{-1, -1}) {
			return "NO";
		}
		
		auto getPath = [&] (coord src) {
			int row = src[0], col = src[1];
			string path = "";
			
			while (isValid(row, col) && from[row][col] != -1) {
				int dir = from[row][col];
				path += symbol[dir];
				row -= dx[dir];
				col -= dy[dir];
			}
			
			reverse(path.begin(), path.end());
			return path;
		};
		
		string path = getPath(dest);
		
		return path;
	};
	
	string ans = bfs (src);
	
	if(ans == "NO") {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	cout << ans.length() << endl;
	cout << ans << endl;
	
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
