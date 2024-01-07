
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
 
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
 
    for (int i = 0; i < n; i++) {
        q.push(q.front());
        q.pop();
 
        cout << q.front() << " ";
 
        q.pop();
    }
 
	return 0;
}
