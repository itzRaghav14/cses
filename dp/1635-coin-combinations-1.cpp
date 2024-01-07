
#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"
 
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 2e5;
const int MAX = (1 << 9);
 
void init1(){
    #ifndef ONLINE_JUDGE
        freopen("xinput.txt", "r", stdin);
        freopen("xoutput.txt", "w", stdout);
    #endif
}
 
void init2(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("xerror1.txt", "w", stderr);
    #endif
}
 
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { out << "[ "; for (const auto &x : v) out << x << ' '; out << "] "; return out; }
 
int f(int tar, int n, vector<int> &a, vector<int> &dp) {
    if(tar == 0) {
        return 1;
    }
    
    if(tar < 0) {
        return 0;
    }
    
    if(dp[tar] != -1) {
        return dp[tar];
    }
    
    int ways = 0;
    
    for(int i = 0; i < n; i++) {
        ways += f(tar - a[i], n, a, dp);
        if(ways >= MOD) ways -= MOD;
    }
    
    return dp[tar] = ways;
    
}
 
void solve() {
    
    int n, tar;
    cin >> n >> tar;
    
    vector<int> a(n);
    cin >> a;
    
    vector<int> dp(tar + 1, -1);
    
    int ans = f(tar, n, a, dp);
    
    if(ans == 1e7) ans = -1;
    
    cout << ans << endl;
    
}
 
int32_t main() {
    
    init1();
    init2();
    
    int t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}
 
