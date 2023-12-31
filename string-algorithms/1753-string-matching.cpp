
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
 
 
struct StringHashing {
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {10009,10007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
 
    StringHashing(string a) {
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        s = a;
        n = s.length();
        
        for (int i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
        }
 
        for (int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
 
    void addCharacter(char ch) {
        s += ch;
        n = s.size();
 
        for (int i = 0; i < primes; i++) {
            while (powersOfBase[i].size() < s.size()) {
                powersOfBase[i].push_back((powersOfBase[i].back() * base) % hashPrimes[i]);
            }
        }
 
        for (int i = 0; i < primes; i++) {
            while (hashValues[i].size() < s.size()) {
                if (hashValues[i].empty()) {
                    hashValues[i].push_back((s[0] - 'a' + 1LL) % hashPrimes[i]);
                } else {
                    ll extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][s.size() - 1]) % hashPrimes[i];
                    hashValues[i].push_back((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
 
    vector<ll> substringHash(int l, int r) {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++) {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), mminvprime(powersOfBase[i][l], hashPrimes[i]), hashPrimes[i]);
        }
        return hash;
    }
 
    bool compareSubstrings(int l1, int r1, int l2, int r2) {
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        for (int i = 0; i < primes; i++) {
            ll val1 = mod_sub(hashValues[i][r1], (l1 > 0 ? hashValues[i][l1 - 1] : 0LL), hashPrimes[i]);
            ll val2 = mod_sub(hashValues[i][r2], (l2 > 0 ? hashValues[i][l2 - 1] : 0LL), hashPrimes[i]);
            if (mod_mul(val1, powersOfBase[i][l2 - l1], hashPrimes[i]) != val2)
                return false;
        }
        return true;
    }
 
    ll mod_mul(ll a, ll b, ll m) {
        return (a * b) % m;
    }
 
    ll mod_sub(ll a, ll b, ll m) {
        return (a - b + m) % m;
    }
 
    ll mminvprime(ll a, ll m) {
        return binpow(a, m - 2, m);
    }
 
    ll binpow(ll a, ll b, ll m) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
};
 
void solve() {
    
    string str, pattern;
    cin >> str >> pattern;
    
    int n = str.length();
    int m = pattern.length();
    int cnt = 0;
    
    StringHashing strHash(str);
    StringHashing patternHash(pattern);
    
    vector<vector<ll>> req = patternHash.hashValues;
    
    for(int i = 0; i + m <= n; i++) {
        
        vector<ll> substrHash = strHash.substringHash(i, i + m - 1);
        if(req[0][m - 1] == substrHash[0] && req[1][m - 1] == substrHash[1]) {
            cnt++;
        }    
    }
    
    cout << cnt << endl;
    
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
 
