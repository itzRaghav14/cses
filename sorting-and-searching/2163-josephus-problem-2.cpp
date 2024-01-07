
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int n, k;
	cin >> n >> k;
 
	vector<int> seg(2 * n + 2);
	for (int i = 1; i <= n; i++) seg[i + n + 1] = 1;
	for (int i = n; i > 0; i--) seg[i] = seg[2 * i] + seg[2 * i + 1];
 
	auto add = [&] (int i, int v) {
		for (seg[i += n + 1] += v; i > 1; i /= 2) seg[i / 2] = seg[i] + seg[i ^ 1];
	};
 
	auto sum = [&] (int l, int r) {
		int res = 0;
		for (l += n + 1, r += n + 2; l < r; l /= 2, r /= 2) {
			if (l & 1) res += seg[l++];
			if (r & 1) res += seg[--r];
		}
		return res;
	};
 
	auto find = [&] (int start, int p) {
		int s = start, e = n;
		int res = e;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (sum(start, mid) >= p) {
				res = mid;
				e = mid - 1;
			} else s = mid + 1;
		}
		return res;
	};
 
	int rem = n;
	int last = 0;
	
	while (rem > 0) {
		int p = k % rem + 1;
 
		if (p > sum(last + 1, n)) {
			p -= sum(last + 1, n);
			last = 0;
		}
 
		last = find(last + 1, p);
		add(last, -1);
		cout << last << " ";
 
		rem--;
	}
 
	return 0;
}
