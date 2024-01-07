
#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 100;
const int MAX = 1e6;
 
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
 
void solve() {
    
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    cin >> coins;
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    
    for(int ind = 0; ind < n; ind++) {
        for(int sum = 0; sum <= x; sum++) {
            
            dp[ind + 1][sum] = (dp[ind + 1][sum] + dp[ind][sum]) % MOD;
            if(sum + coins[ind] <= x) dp[ind][sum + coins[ind]] = (dp[ind][sum + coins[ind]] + dp[ind][sum]) % MOD;
            
        }
    }
    
    // cout << dp << endl;
    
    cout << dp[n][x] << endl;
    
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
 
