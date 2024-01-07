
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, a, b) for (int i = a; i >= b; i--)
#define repo(i, b) for (int i = 0; i < b; i++)
#define trav(a, x) for (auto &a : x)
 
#define seti set<int>
#define useti unordered_set<int>
#define mapii map<int, int>
#define umapii unordered_map<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define pi pair<int, int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define prq priority_queue
 
#define pb push_back
#define ppb pop_back()
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(var) var.begin(), var.end()
#define present(c, x) (c.find(x) != c.end())
#define desc greater<int>()
#define itos to_string
 
#define imin INT_MIN
#define imax INT_MAX
#define lmin LLONG_MIN
#define lmax LLONG_MAX
 
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
 
#define spc << " " <<
#define spcend << " "
#define ndl << "\n"
#define cndl cout << "\n"
#define endl "\n"
 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yes cout << "yes\n"
#define no cout << "no\n"
#define minus1 cout << "-1\n"
#define zero cout << "0\n"
 
#define precision(n) cout << fixed << setprecision(n);
#define MOD (ll)1000000007
 
// ------------------------------------
 
bool isPrime(ll n){
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6){
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
 
ll power(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1) res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}
 
ll powermod(ll a, ll b, ll Mod = MOD){
    ll res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % Mod;
        a = (a * a) % Mod;
        b = b >> 1;
    }
    return res;
}
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return (a / gcd(a, b) * b);
}
 
ll nCr(ll n, ll r){
    ll p = 1, k = 1;
    if(n - r < r) r = n - r;
    while(r){
        p *= n;
        k *= r;
        int m = gcd(p, k);
        p /= m;
        k /= m;
        n--;
        r--;
    }
    return p;
}
 
int lsb(ll n){
    if(n==0) return -1;
    int res = 0;
    while(n){
        if(n & 1) return res;
        n /= 2;
        res++;
    }
    return -1;
}
 
int msb(ll n){
    if (n == 0) return -1;
    int res = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        res++;
    }
 
    return res;
}
 
int mex(vi arr) {
    int n = arr.size();
    umapii mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    for (int i = 0; i <= n + 1; i++) {
        if (mp[i] == 0) {
            return i;
        }
    }
    return n + 1;
}
 
 
 
int digitsum(ll n){
    int ans = 0;
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
 
bool is_palindrome(vector<int> &s){
    int n = s.size();
    int lo = 0;
    int hi = n - 1;
    while (lo < hi){
        if (s[lo] != s[hi]){
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}
 
bool is_palindrome(string &s){
    int n = s.length();
    int lo = 0;
    int hi = n - 1;
    while (lo < hi){
        if (s[lo] != s[hi]){
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}
 
bool is_palindrome(int n){
    vi v;
    while (n > 0){
        v.pb(n % 10);
        n = n / 10;
    }
    reverse(all(v));
    return is_palindrome(v);
}
 
int modM(ll n, ll m){
    return ((n % MOD * m % MOD) + MOD) % MOD;
}
 
int modA(ll n, ll m, ll M = MOD){
    return ((n % M + m % M) + M) % M;
}
 
vi prefixArray(vi &vec){
    vi pre(1, 0);
    for(auto &x:vec) pre.pb(pre.back() + x);
    return pre;
}
 
vi postfixArray(vi &vec){
    vi post(vec.size()+1);
    post.back() = 0;
    for(int i=vec.size()-1; i>=0; i--){
        post[i] = post[i+1] + vec[i];
    }
    return post;
}
 
string decToBinary(ll n){
    string binaryNum;
    int i = 0;
    while (n > 0) {
        binaryNum.pb('0' + n%2);
        n /= 2;
        i++;
    }
    reverse(all(binaryNum));
    return binaryNum;
}
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#define debugs(x,y) cerr << #x<<" "; _print(y); cerr << endl;
#define crndl cerr << endl;
#else
#define debug(x);
#define debugs(x,y);
#define crndl;
#endif
 
typedef unsigned long long ull;
typedef long double lld;
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
// ------------------------------------
 
void solve();
 
void init(){
    #ifndef ONLINE_JUDGE
        freopen("xinput.txt", "r", stdin);
        freopen("xoutput.txt", "w", stdout);
        freopen("xerror.txt", "w", stderr);
    #endif
}
 
signed main(){
        
    init();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        crndl;
        
    }
    return 0;
}
 
#define int long long int
 
void solve(){
    
    string S;
    cin >> S;
    
    int ans = 0;
    
    for(int i=0; i<S.length();){
        int j = i;
        while(S[i]==S[j]) i++;
        ans = max(ans, i-j);
    }
    
    cout << ans << endl;
    
}
 
 
/*
 
ROUGH WORK
 
 
 
-----------------------------------
 
 
 
-----------------------------------
 
 
 
-----------------------------------
 
 
 
*/
