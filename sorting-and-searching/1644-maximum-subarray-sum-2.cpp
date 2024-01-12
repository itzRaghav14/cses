#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<long long> pre(n + 1, 0);
	for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];

	vector<long long> seg(2 * n + 2);
	for (int i = 0; i <= n; i++) seg[i + n + 1] = pre[i];
	for (int i = n; i > 0; i--) seg[i] = max(seg[i << 1], seg[i << 1 | 1]);

	auto getMax = [&] (int l, int r) {
		long long res = -1e17;
		for (l += n + 1, r += n + 2; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = max(res, seg[l++]);
			if (r & 1) res = max(res, seg[--r]);
		}
		return res;
	};

	long long ans = -1e17;
	
	for (int i = 0; i < n; i++) {
		int start = i + a, end = min(n, i + b);
		if (start > n) break;
		ans = max(ans, getMax(start, end) - pre[i]);
		if (i == 0) {
			cerr << getMax(start, end) << endl;
		}
	}

	cout << ans << endl;

	return 0;
}
