#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
    int n, m;
    cin >> n >> m;
 
    vector<int> h(n), r(m);
    for (int i = 0; i < n; i++) 
        cin >> h[i];
 
    for (int i = 0; i < m; i++) 
        cin >> r[i];
    
    vector<int> seg(2 * n);
    for (int i = 0; i < n; i++) seg[i + n] = h[i];
    for (int i = n - 1; i > 0; i--) seg[i] = max(seg[2 * i], seg[2 * i + 1]);
 
    auto add = [&] (int i, int v) {
        for (seg[i += n] += v; i > 1; i /= 2) seg[i / 2] = max(seg[i], seg[i ^ 1]);
    };
 
    auto getMax = [&] (int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(res, seg[--r]);
        }
        return res;
    };
 
    auto getSeg = [&] () {
        return vector<int>{seg.begin() + n, seg.end()};
    };
 
    auto firstLarger = [&] (int v) {
        int s = 0, e = n - 1; 
        int res = n;
        while (s <= e) {
            int m = (s + e) / 2;
            int mx = getMax(0, m);
            if (mx >= v) {
                res = m;
                e = m - 1;
            } else s = m + 1;
        }
        return res;
    };
 
    vector<int> ans(m, 0);
 
    for (int i = 0; i < m; i++) {
        int idx = firstLarger(r[i]);
        if (idx < n) {
            ans[i] = idx + 1;
            add(idx, -r[i]);
        }
    }
	
    for (int x : ans) {
        cout << x << " ";
    } cout << endl;
 
    return 0;
}
