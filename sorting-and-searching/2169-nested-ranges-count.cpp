
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
    
    int n;
    cin >> n;
 
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
 
    sort(a.begin(), a.end());
 
    // doing coordinate compression
    vector<int> b;
    for (int i = 0; i < n; i++) {
        b.push_back(a[i][1]);
    }
    sort(b.begin(), b.end());
 
    auto find = [&] (int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };
 
    // creating segment tree
    vector<int> seg1(2 * n), seg2(2 * n);
 
    auto add = [&] (vector<int> &seg, int i, int v) {
        for (seg[i += n] += v; i > 1; i /= 2) seg[i / 2] = seg[i] + seg[i ^ 1];
    };
 
    auto sum = [&] (vector<int> &seg, int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res += seg[l++];
            if (r & 1) res += seg[--r];
        }
        return res;
    };
 
    auto insert = [&] (vector<int> &seg, int val) {
        int index = find(val);
        add(seg, index, 1);
    };
 
    auto remove = [&] (vector<int> &seg, int val) {
        int index = find(val);
        add(seg, index, -1);
    };
 
    // adding all the end points first
    for (int i = 0; i < n; i++) {
        insert(seg2, a[i][1]);
    }
 
    int indexStart = 0, indexEnd = 0;
 
    dbg(b); dbg(seg2); dbg();
 
    for (int i = 0; i < n; i++) {
        int start = a[i][0], end = a[i][1];
 
        while (indexStart < n && a[indexStart][0] <= start) {
            insert(seg1, a[indexStart][1]);
            indexStart++;
        }
 
        while (indexEnd < n && a[indexEnd][0] < start) {
            remove(seg2, a[indexEnd][1]);
            indexEnd++;
        }
 
        remove(seg1, end);
        remove(seg2, end);
 
        dbg(i); dbg(seg1); dbg(seg2); dbg();
 
        // intervals with starting >= start and ending <= end
        {
            int cnt = sum(seg2, 0, find(end));
            a[i][3] = cnt;
        }
 
        // intervals with starting <= start and ending >= end
        {
            int cnt = sum(seg1, find(end), n - 1);
            a[i][4] = cnt;
        }
 
        insert(seg1, end);
        insert(seg2, end);
    }
 
    sort(a.begin(), a.end(), [&] (auto left, auto right) {
        return left[2] < right[2];
    });
 
    for (auto it : a) cout << it[3] << " "; cout << endl;
    for (auto it : a) cout << it[4] << " "; cout << endl;
 
	return 0;
}
