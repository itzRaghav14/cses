
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
const int N = 19;
const int D = 10;
 
int n;
string low, high;
long long dp[N][D][2][2][2];
 
long long f (int idx, int last, int lowTight, int highTight, int nonZero) {
	
	if(idx == n) {
		return 1;
	}
	
	long long &state = dp[idx][last][lowTight][highTight][nonZero];
	if(state != -1) {
		return state;
	}
	
	long long res = 0;
	int start = lowTight ? low[idx] - '0' : 0;
	int end = highTight ? high[idx] - '0' : 9;
	
	for(int i = start; i <= end; i++) {
		int newLowTight = lowTight && i == start;
		int newHighTight = highTight && i == end;
		int newNonZero = nonZero || i > 0;
		
		if(idx > 0 && nonZero && i == last) continue;
		
		long long curr = f (idx + 1, i, newLowTight, newHighTight, newNonZero);
		
		res += curr;
	}
	
	return state = res;
	
}
 
void equalize () {
	
	int n1 = low.size();
	int n2 = high.size();
	int n = abs(n1 - n2);
	string pre(n, '0');
	
	if(n1 < n2) {
		low = pre + low;
	}
	
	else if(n1 > n2) {
		high = pre + high;
	}
	
}
 
void solve() {
	
	cin >> low >> high;
	
	equalize();
	
	n = low.size();
	
	debug(inputs, n, low, high);
	
	memset(dp, -1, sizeof dp);
	
	long long res = f(0, 0, 1, 1, 0);
	
	cout << res << endl;
	
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
