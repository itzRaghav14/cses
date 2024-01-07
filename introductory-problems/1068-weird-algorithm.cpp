
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
	
	long long n;
	cin >> n;
	
	while(n != 1) {
		cout << n << " ";
		if(n & 1) n = n * 3 + 1;
		else n /= 2;
	}
	
	cout << 1 << endl;
	
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
	
	for(int _t = 0; _t < t; _t++) {
		solve();
	}
	
	return 0;
}
