
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
 
    vector<vector<int>> a(n, vector<int>(4));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
 
    sort(a.begin(), a.end());
 
    set<int> free;
    set<pair<int,int>> busy;
 
    int rooms = 0;
 
    for (int i = 0; i < n; i++) {
        int start = a[i][0], end = a[i][1];
 
        while (!busy.empty()) {
            auto [endTime, room] = *busy.begin();
            if (endTime >= start) break;
            busy.erase(busy.begin());
            free.insert(room);
        }
 
        if (free.empty()) {
            free.insert(++rooms);
        }
 
        int room = *free.begin();
        a[i][3] = room;
        free.erase(room);
        busy.insert({a[i][1], room});
    }
 
    sort(a.begin(), a.end(), [&] (auto left, auto right) {
        return left[2] < right[2];
    });
 
    cout << rooms << endl;
    for (auto it : a) cout << it[3] << " "; cout << endl;
 
	return 0;
}
