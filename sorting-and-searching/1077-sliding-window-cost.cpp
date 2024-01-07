#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> b = a;
	sort(b.begin(), b.end());
	
	auto find = [&] (int val) {
		return lower_bound(b.begin(), b.end(), val) - b.begin();
	};

	vector<long long> cnt(2 * n), sum(2 * n);

	auto add = [&] (vector<long long> &seg, int i, int v) {
		for (seg[i += n] += v; i > 1; i >>= 1) seg[i >> 1] = seg[i] + seg[i ^ 1];
	};

	auto getSum = [&] (vector<long long> &seg, int l, int r) {
		long long res = 0;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += seg[l++];
			if (r & 1) res += seg[--r];
		}
		return res;
	};

	auto findK = [&] () {
		int s = 0, e = n - 1;
		int res = e;
		while (s <= e) {
			int m = (s + e) / 2;
			if (getSum(cnt, 0, m) >= (k + 1) / 2) {
				res = m;
				e = m - 1;
			} else s = m + 1;
		}
		return res;
	};

	for (int i = 0; i < n; i++) {
		add(cnt, find(a[i]), 1);
		add(sum, find(a[i]), a[i]);

		if (i >= k) {
			add(cnt, find(a[i - k]), -1);
			add(sum, find(a[i - k]), -a[i - k]);
		}

		if (i >= k - 1) {
			int medianIndex = findK();
			long long res = 0;
			res += getSum(cnt, 0, medianIndex) * b[medianIndex] - getSum(sum, 0, medianIndex);
			res += getSum(sum, medianIndex + 1, n - 1) - getSum(cnt, medianIndex + 1, n - 1) * b[medianIndex];
			cout << res << " ";
		}
	}
	
	return 0;
}
