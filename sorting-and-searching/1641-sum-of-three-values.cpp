
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, x;
	cin >> n >> x;
 
	vector<array<int,2>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}
 
	sort(a.begin(), a.end());
	bool ok = false;
 
	for (int first = 0; first < n; first++) {
		int second = first + 1, third = n - 1;
		int target = x - a[first][0];
 
		while (second < third) {
			int sum = a[second][0] + a[third][0];
			if (sum == target) {
				ok = true;
				break;
			}
			if (sum > target) third--;
			else second++;
		}
 
		if (ok) {
			cout << a[first][1] << " " << a[second][1] << " " << a[third][1];
			break;
		}
	}
 
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
	}
 
	return 0;
}
