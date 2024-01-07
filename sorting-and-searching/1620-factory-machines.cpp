
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#endif
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, t;
    cin >> n >> t;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    auto isValid = [&] (long long time) {
        long long rem = t;
        for (int i = 0; i < n; i++) {
            rem -= time / a[i];
            if (rem <= 0) return true;
        }
        return false;
    };
 
    long long start = 1, end = 1e18;
    long long ans = end;
 
    while (start <= end) {
        long long mid = (start + end) / 2;
        bool check = isValid(mid);
        if (check) {
            ans = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
 
    cout << ans << endl;
 
	return 0;
}
