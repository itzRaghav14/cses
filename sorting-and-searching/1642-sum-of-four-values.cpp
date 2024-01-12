#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
	int n, x;
	cin >> n >> x;

	vector<array<int,2>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}

	sort(a.begin(), a.end());
	map<int, pair<int,int>> mp;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			mp[a[i][0] + a[j][0]] = {i, j};
		}
	}

	for (int first = 0; first < n; first++) {
		for (int second = first + 1; second < n; second++) {
			int target = x - a[first][0] - a[second][0];
			if (mp.find(target) != mp.end()) {
				auto [third, fourth] = mp[target];
				if (third > second) {
					cout << a[first][1] << " " << a[second][1] << " " << a[third][1] << " " << a[fourth][1];
					return 0;
				}
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

	return 0;
}
