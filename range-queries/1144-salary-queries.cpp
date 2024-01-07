
#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename Type, typename ComparatorFn = less<Type>>
using oset = tree<Type, null_type, ComparatorFn, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename Type, typename ComparatorFn>
bool oset_erase (oset<Type, ComparatorFn> &st, Type val) {
	if (st.lower_bound(val) == st.upper_bound(val)) return false;
	st.erase(st.find_by_order(st.order_of_key(val)));
	return true;
}
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#endif
 
void solve() {
 
	int n, q;
	cin >> n >> q;
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
 
	oset<int, less_equal<int>> st{a.begin(), a.end()};
 
	while (q--) {
		char type;
		cin >> type;
 
		if (type == '!') {
			int k, x;
			cin >> k >> x;
			k--;
 
			// pop the element from the set and insert the new element
			oset_erase(st, a[k]);
			a[k] = x;
			st.insert(a[k]);
		}
 
		else {
			int low, high;
			cin >> low >> high;
 
			int res = n;
 
			// find the number of elements lesser than low
			res -= st.order_of_key(low);
 
			// find the number of elements greater than high
			res -= (n - st.order_of_key(high + 1));
 
			cout << res << endl;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t = 1;
	// cin >> t;
 
	for (int tc = 1; tc <= t; tc++) {
		debug(Testcase, tc);
		solve();
		dbg();
	}
	
    return 0;
}
