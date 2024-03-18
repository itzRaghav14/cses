#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefix_function(string str) {
    int n = str.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && str[pi[j]] != str[i]) {
            j = pi[j] - 1;
        }
        if (j >= 0) pi[i] = pi[j] + 1;
    }
    return pi;
}
 
int search(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    string str = pattern + "#" + text;
    vector<int> pi = prefix_function(str);
 
    int ans = 0;
    for (int i = 2 * m; i <= n + m; i++) {
        if (pi[i] >= m) ans++;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    string text, pattern;
    cin >> text >> pattern;
 
    cout << search(text, pattern);
 
    return 0;
}
