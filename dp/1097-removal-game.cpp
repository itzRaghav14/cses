
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
const int N = 5e3 + 5;
 
int a[N];
long long dp[N][N];
 
void solve() {
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int left = n - 1; left >= 0; left--) {
		for(int right = left; right < n; right++) {
			
			int turn = (right - left + 1) & 1 ^ (n & 1 ^ 1);
			
			if(left == right) {
				dp[left][right] = turn * a[left];
				continue;
			}
			
			long long pickLeft = turn * a[left] + dp[left + 1][right];
			long long pickRight = turn * a[right] + dp[left][right - 1];
			
			dp[left][right] = turn == 1 ?
				max(pickLeft, pickRight) :
				min(pickLeft, pickRight);
			
		}
	}
	
	cout << dp[0][n - 1] << endl;
	
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
