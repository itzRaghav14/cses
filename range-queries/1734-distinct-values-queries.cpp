
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int n, q;
	cin >> n >> q;
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	vector<vector<int>> queries(q, vector<int>(3));
	for (int i = 0; i < q; i++) {
		cin >> queries[i][0] >> queries[i][1];
		queries[i][0]--, queries[i][1]--;
 
		queries[i][2] = i;
	}
 
	sort(queries.begin(), queries.end(), [&] (auto left, auto right) {
		return left[1] < right[1];
	});
 
	vector<int> ans(q, 0);
	vector<int> bit(n + 1, 0);
	map<int,int> prev;
	int index = 0;
 
	auto add = [&] (int i, int v) {
		for (++i; i <= n; i += i & -i) {
			bit[i] += v;
		}
	};
 
	auto sum = [&] (int i) {
		int res = 0;
		for (++i; i > 0; i -= i & -i) {
			res += bit[i];
		}
		return res;
	};
 
	auto getSum = [&] (int l, int r) {
		if (l == 0) return sum(r);
		return sum(r) - sum(l - 1);
	};
 
	for (int i = 0; i < n; i++) {
		int val = a[i];
		if (prev.find(val) != prev.end()) {
			add(prev[val], -1);
		}
		add(i, 1);
		prev[val] = i;
 
		while (index < q && queries[index][1] == i) {
			int left = queries[index][0], right = queries[index][1], idx = queries[index][2];
			ans[idx] = getSum(left, right);
			index++;
		}
	}
 
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
 
    return 0;
}
