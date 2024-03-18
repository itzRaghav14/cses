#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string str) {
    int n = str.length();
    vector<int> pi(n, 1);
    for (int i = 2; i < n; i++) {
        int j = i - 2;
        while (j >= 1 && str[pi[j]] != str[i]) {
            j = pi[j] - 2;
        }
        if (j >= 1) pi[i] = pi[j] + 1;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;

    int n = str.length();
    vector<int> pi = prefix_function(str);

    vector<int> ans;
    int p = pi[n - 2];

    while (p > 1) {
        ans.push_back(p);
        p = pi[p - 2];
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";

    return 1;
}
