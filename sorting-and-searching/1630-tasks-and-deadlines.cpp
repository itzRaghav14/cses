
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int n;
	cin >> n;
 
	long long ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int duration, deadline;
		cin >> duration >> deadline;
		ans += deadline;
		a[i] = duration;
	}
 
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++) {
		ans -= 1LL * a[i] * (n - i);
	}
 
	cout << ans << endl;
 
	return 0;
}
