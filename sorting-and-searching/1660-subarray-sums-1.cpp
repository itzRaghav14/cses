
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
 
	long long sum = 0;
	long long ans = 0;
	map<long long, int> mp;
 
	mp[0]++;
 
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans += mp[sum - x];
		mp[sum]++;
	}
 
	cout << ans << endl;
 
	return 0;
}
