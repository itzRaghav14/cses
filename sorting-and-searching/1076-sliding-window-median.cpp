#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	multiset<int> small, big;

	auto equilibrium = [&] () {
		if (small.size() + 1 <= big.size()) {
			small.insert(*big.begin());
			big.erase(big.begin());
		} 
		if (small.size() >= big.size() + 2) {
			big.insert(*small.rbegin());
			small.erase(--small.end());
		}
		while (!small.empty() && !big.empty() && *small.rbegin() > *big.begin()) {
			small.insert(*big.begin());
			big.insert(*small.rbegin());
			small.erase(--small.end());
			big.erase(big.begin());
		}
	};

	for (int i = 0; i < n; i++) {
		small.insert(a[i]);
		equilibrium();

		if (i >= k) {
			if (small.find(a[i - k]) != small.end()) small.erase(small.find(a[i - k]));
			else if (big.find(a[i - k]) != big.end()) big.erase(big.find(a[i - k]));
			equilibrium();
		}

		if (i >= k - 1) cout << *small.rbegin() << " ";
	}
	
	return 0;
}
