#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
const int MOD = 1e9 + 7;
const int MX = 1e9;
 
template <typename T>
class PreMatrix {
private:
	int n, m;
	vector<vector<long long>> pre;
	
	long long getVal (T key) {
		int val = 0;
		if(key == '*') val = 1;
		return val;
	}
	
	long long get (int row, int col) {
		if(row < 0 || row >= n || col < 0 || col >= m) {
			return 0;
		}
		return pre[row][col];
	}
	
	long long add (int a, int b) {
		return a + b;
	}
	
	long long diff (int a, int b) {
		return a - b;
	}
	
	void build () {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				pre[i][j] = add(get(i, j), get(i - 1, j));
				pre[i][j] = add(get(i, j), get(i, j - 1));
				pre[i][j] = diff(get(i, j), get(i - 1, j - 1));
			}
		}
	}
	
public:
	
	PreMatrix (vector<string> &mat) {
		n = mat.size();
		m = n ? mat[0].size() : 0;
		pre.resize(n, vector<long long> (m, 0));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				pre[i][j] = getVal(mat[i][j]);
			}
		}
		build();
	}
	
	PreMatrix (vector<vector<T>> &mat) {
		n = mat.size();
		m = n ? mat[0].size() : 0;
		pre.resize(n, vector<long long> (m, 0));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				pre[i][j] = getVal(mat[i][j]);
			}
		}
		build();
	}
	
	long long query (int sRow, int sCol, int eRow, int eCol) {
		long long sum = 0;
		sum = add(sum, get(eRow, eCol));
		sum = add(sum, get(sRow - 1, sCol - 1));
		sum = diff(sum, get(sRow - 1, eCol));
		sum = diff(sum, get(eRow, sCol - 1));
		return sum;
	}
};
 
void solve() {
	
	int n, q;
	cin >> n >> q;
	
	vector<string> a(n, string(n, '?'));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	PreMatrix<char> pre(a);
	
	for(int _q = 1; _q <= q; _q++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		int res = pre.query(a, b, c, d);
		cout << res << endl;
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
