#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = (a[i] % n + n) % n;
	}

	long long ans = 0;
	int sum = 0;
	vector<int> cnt(n, 0);
	cnt[0] = 1;

	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum = (sum % n + n) % n;
		ans += cnt[sum];
		cnt[sum]++;
	}

	cout << ans << endl;
	
	return 0;
}
