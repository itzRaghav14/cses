#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif
 
const int MOD = 1e9 + 7;
const int MX = 1e9;
 
// === Segment Tree ===
struct Node;
 
template <typename T, typename Node = Node>
class SegmentTree{
private: 
	int size = 0;
	vector<Node> seg;
		
    void build (int low, int high, int ind, vector<T> &arr) {
    	if(low == high) {
    		seg[ind] = Node(arr[low]);
    		return;
    	}
    	int mid = (low + high) / 2;
    	int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    	build(low, mid, leftInd, arr);
    	build(mid + 1, high, rightInd, arr);
    	seg[ind].merge(seg[leftInd], seg[rightInd]);
    }
	
	Node query (int low, int high, int ind, int left, int right) {
		if(low > right || high < left) {
			return Node();
		}
		if(low >= left && high <= right) {
			return seg[ind];
		}
		int mid = (low + high) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		Node res;
		Node leftItem = query(low, mid, leftInd, left, right);
		Node rightItem = query(mid + 1, high, rightInd, left, right);
		res.merge(leftItem, rightItem);
		return res;
	}
	
	void update (int low, int high, int ind, int index, int value) {
		if(low == high) {
			seg[ind] = Node(value);
			return;
		}
		int mid = (low + high) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		if(index <= mid) update(low, mid, leftInd, index, value);
		else update(mid + 1, high, rightInd, index, value);
		seg[ind].merge(seg[leftInd], seg[rightInd]);
	}
	
public:
	SegmentTree () {
		
	}
    
    SegmentTree (int n) {
    	size = n;
    	seg.resize(4 * size + 1);
    }
    
    SegmentTree (vector<T> &arr) {
    	size = arr.size();
    	seg.resize(4 * size + 1);
    	build(arr);
    }
    
    void build (vector<T> &arr) {
    	build(0, size - 1, 0, arr);
    }
    
    Node query (int left, int right) {
    	return query(0, size - 1, 0, left, right);
    }
    
    void update (int index, int value) {
    	return update(0, size - 1, 0, index, value);
    }
};
 
struct Node {
    long long sum;
    int mx, mn;
    
    Node () : sum(0), mx(-MX), mn(MX) {}
    
    Node (int val) : sum(val), mx(val), mn(val) {}
    
    void merge (Node &left, Node &right) {
    	sum = left.sum + right.sum;
    	mx = max(left.mx, right.mx);
    	mn = min(left.mn, right.mn);
    }
};
 
 
void solve() {
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	SegmentTree<int> sg(a);
	
	while(q--) {
		
		int type;
		cin >> type;
		
		if (type == 1) {
			int index, value;
			cin >> index >> value;
			index--;
			sg.update(index, value);
		}
		
		else if (type == 2) {
			int left, right;
			cin >> left >> right;
			left--, right--;
			Node res = sg.query(left, right);
			cout << res.mn << endl;
		}
	}
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
