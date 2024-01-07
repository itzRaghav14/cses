
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;
 
#define int long long
#define rep(i, a, b) for(int i=a; i<b; i++)
#define repn(i, a, b) for(int i=a; i>=b; i--)
#define repo(i, b) for(int i=0; i<b; i++)
#define trav(a, x) for(auto &a:x)
 
#define vi vector<int>
#define vs vector<string>
#define pi pair<int,int>
#define vvi vector<vi>
#define vpi vector<pi>
#define vsi vector<string>
#define vvpi vector<vpi>
#define mapii map<int,int>
#define umapii unordered_map<int,int>
#define umap unordered_map
#define prq priority_queue
 
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define lb lower_bound
#define ub upper_bound
#define itos to_string
#define fi first
#define se second
#define desc greater<int>()
#define sz(x) (int)(x).size()
#define len(x) (int)(x).length()
#define all(x) x.begin(), x.end()
 
#define spc << " " <<
#define spcd << " "
#define endl "\n"
#define ndl << "\n"
#define cndl cout << "\n"
#define coutt(x) cout << x << endl
 
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yes cout << "yes\n"
#define no cout << "no\n"
#define minus1 cout << "-1\n"
#define zero cout << "0\n"
 
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << #x<<" "; _print(x); cerr << endl;
#define debug(x,y...) cerr << #x<<" -> "; _print(y); cerr << endl;
#define crndl cerr << "\n";
#else
#define dbg(x...);
#define debug(x,y...);
#define crndl;
#endif
 
void init1(){
    #ifndef ONLINE_JUDGE
        freopen("xinput.txt", "r", stdin);
        freopen("xoutput.txt", "w", stdout);
    #endif
}
 
void init2(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("xerror.txt", "w", stderr);
    #endif
}
 
typedef unsigned long long ull;
typedef long double lld;
// template<class T> using oset =tree<T, null_type, greater_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // *find_by_order, order_of_key
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << "\"" << t << "\"";}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print() {return;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class... V> void _print(T t, V... v) {_print(t); if(sizeof...(v)) {cerr<<", "; _print(v...);}}
// template <class T> void _print(oset<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int MOD = (int)1000000007;
int INF = (int)1000000000000000000;
// int MOD = (int)998244353;
 
 
// ---------------------------------------------------------------------------------------------
 
void preSolve();
void solve(int);
 
signed main(){
    init1();
    init2();
    int t = 1;
    // cin >> t;
    // auto start1 = high_resolution_clock::now();
    preSolve();
    rep(i, 1, t+1){
        // cout << "Case #" << i << ": ";
        debug(testcase, i);
        solve(i);
        crndl;
    }
    // auto stop1 = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop1 - start1);
    // #ifndef ONLINE_JUDGE
    //     cerr << "Time: " << duration.count() / 1000 << endl;
    // #endif
    return 0;
}
 
constexpr int N = 2e5;
constexpr int NP = 1e12;
 
void preSolve(){
    return;
}
 
vsi mat(8, string("........"));
 
bool inRange(int i, int j){
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}
 
bool isValid(int row, int col){
    
    if(mat[row][col] == '*') return false;
    
    for(int i = 0; i < 8; i++){
        if(mat[i][col] == 'Q') return false;
        if(mat[row][i] == 'Q') return false;
    }
    
    for(int i = -8; i < 8; i++){
        int x = row + i, y = col + i;
        if(inRange(x, y) && mat[x][y] == 'Q') return false;
        y = col - i;
        if(inRange(x, y) && mat[x][y] == 'Q') return false;
    }
    
    return true;
    
}
 
int f(int i, int j, int placed){
    
    if(placed == 8){
        return 1;
    }
    
    if(j == 8) {
        j = 0;
        i++;
    }
    
    if(i == 8){
        return 0;
    }
    
    int notPlace = f(i, j + 1, placed);
    int place = 0;
    
    if(isValid(i, j)){
        mat[i][j] = 'Q';
        place = f(i, j + 1, placed + 1);
        mat[i][j] = '.';
    }
    
    return place + notPlace;
    
}
 
void solve(int testCase){
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> mat[i][j];
        }
    }
    
    cout << f(0, 0, 0) << endl;
    
}
 
