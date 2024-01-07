#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) 
        cin >> p[i];
    
    vector<int> seg(2 * n);
    for (int i = 0; i < n; i++) seg[i + n] = 1;
    for (int i = n - 1; i > 0; i--) seg[i] = seg[2 * i] + seg[2 * i + 1];
 
    auto add = [&] (int i, int v) {
        for (seg[i += n] += v; i > 1; i /= 2) seg[i / 2] = seg[i] + seg[i ^ 1];
    };
 
    auto getSum = [&] (int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res += seg[l++];
            if (r & 1) res += seg[--r];
        }
        return res;
    };
    
    auto getIth = [&] (int idx) {
        int s = 0, e = n - 1;
        int res = n;
        while (s <= e) {
            int mid = (s + e) / 2;
            int ct = getSum(0, mid);
            if (ct >= idx) {
                res = mid;
                e = mid - 1;
            } else s = mid + 1;
        }
        return res;
    };
 
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int idx = getIth(p[i]);
        add(idx, -1);
        ans[i] = a[idx];
    }
 
    for (int x : ans) {
        cout << x << " ";
    } cout << endl;
 
    return 0;
}
