
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
    
	int t;
    cin >> t;
 
    vector<long long> p10 = {1};
    while (p10.back() < 1e17) p10.push_back(p10.back() * 10);
 
    auto cnt = [&] (int digit) {
        return 9 * p10[digit - 1];
    };
 
    while (t--) {
        long long k;
        cin >> k;
 
        k--;
        int digits = 1;
        long long num = 1;
        
        while (k > digits * cnt(digits)) {
            k -= digits * cnt(digits);
            num += cnt(digits);
            digits++;
        }
 
        num += k / digits;
        k %= digits;
 
        cout << to_string(num)[k] << endl;
    }
	
	return 0;
}
