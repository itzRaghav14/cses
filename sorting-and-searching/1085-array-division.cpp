#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long s = 1, e = 1e15;
	long long ans = e;

	auto isValid = [&] (long long limit) {
		int cnt = 0;
		long long sum = limit;
		for (int i = 0; i < n; i++) {
			if (a[i] > limit) return false;
			if (sum + a[i] > limit) {
				cnt++;
				sum = 0;
			}
			sum += a[i];
			if (cnt > k) return false;
		}
		return true;
	};

	while (s <= e) {
		long long mid = (s + e) / 2;
		bool check = isValid(mid);
		if (check) {
			ans = mid;
			e = mid - 1;
		} else s = mid + 1;
	}

	cout << ans << endl;
	
	return 0;
}
