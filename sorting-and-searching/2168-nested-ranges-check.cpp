
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
 
    multiset<int> st1, st2;
    for (int i = 0; i < n; i++) st2.insert(a[i][1]);
 
    int indexStart = 0, indexEnd = 0;
 
    for (int i = 0; i < n; i++) {
        int start = a[i][0], end = a[i][1];
 
        while (indexStart < n && a[indexStart][0] <= start) {
            st1.insert(a[indexStart][1]);
            indexStart++;
        }
 
        while (indexEnd < n && a[indexEnd][0] < start) {
            st2.erase(st2.find(a[indexEnd][1]));
            indexEnd++;
        }
 
        st1.erase(st1.find(end));
        st2.erase(st2.find(end));
 
        // those whose starting >= start and ending <= end
        if (st2.upper_bound(end) != st2.begin()) a[i][3] = 1;
 
        // those whose starting <= start and ending >= end
        if (st1.lower_bound(end) != st1.end()) a[i][4] = 1;
 
        st1.insert(end);
        st2.insert(end);
    }
 
    sort(a.begin(), a.end(), [&] (auto left, auto right) {
        return left[2] < right[2];
    });
 
    for (auto it : a) cout << it[3] << " "; cout << endl;
    for (auto it : a) cout << it[4] << " "; cout << endl;
 
	return 0;
}
