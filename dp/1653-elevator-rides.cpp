
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
// mask -> the people who have been lifted
// lift -> the number of times lift has been used
// dp[lift][mask] -> maximum weight capacity you can have
 
void solve() {
	
	int n, limit;
	cin >> n >> limit;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int mx = 1 << n;
	
	vector<long long> dp (mx, 1e11);
	// mask -> the people who have been picked
	// dp[mask] -> the weight which has been used
	
	// base case -> no weight required for no people
	dp[0] = 0;
	
	auto setMin = [&] (long long &next, long long curr) -> long long {
		return next > curr ? next = curr, 1 : 0;
	};
	
	for(int mask = 0; mask < mx - 1; mask++) {
		for(int i = 0; i < n; i++) {
			int bit = 1 << i;
			if(mask & bit) continue;
			long long nextMultiple = (dp[mask] + limit - 1) / limit * limit;
			int left = nextMultiple - dp[mask];
			
			long long newWeight = a[i] + (a[i] > left ? nextMultiple : dp[mask]);
			setMin (dp[mask | bit], newWeight);
			
		}
	}
	
	dbg(dp);
	
	// answer -> ceil division of dp[mx - 1] by limit
	cout << (dp[mx - 1] + limit - 1) / limit << endl;
 	
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
