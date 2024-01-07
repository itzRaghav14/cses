
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
 
	stack<int> st;
	vector<int> ans(n, 0);
 
	for (int i = 0; i < n; i++) {
		while (!st.empty() && a[st.top()] >= a[i]) {
			st.pop();
		}
		if (!st.empty()) ans[i] = st.top() + 1;
		st.push(i);
	}
 
	for (int x : ans) cout << x << " ";
 
	return 0;
}
