
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int n;
	cin >> n;
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
 
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	int mx = *max_element(a.begin(), a.end());
	long long ans = max(sum, 2LL * mx);
 
	cout << ans << endl;	
 
	return 0;
}
