#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	map<int,int> mp;
	long long ans = 0;
	int start = 0;

	for (int end = 0; end < n; end++) {
		mp[a[end]]++;

		while (mp.size() > k) {
			mp[a[start]]--;
			if (mp[a[start]] == 0) mp.erase(a[start]);
			start++;
		}

		ans += (end - start + 1);
	}

	cout << ans << endl;	
	
	return 0;
}
