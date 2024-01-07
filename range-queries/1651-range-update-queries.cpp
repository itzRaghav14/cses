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
struct Update;
 
template <typename T, typename Node = Node, typename Update = Update>
class LazySegmentTree {
private: 
	int size = 0;
	vector<Node> seg;
	vector<int> lazy;
	vector<Update> updates;
	
    void build (int start, int end, int ind, vector<T> &arr) {
    	if(start == end) {
    		seg[ind] = Node(arr[start]);
    		return;
    	}
    	int mid = (start + end) / 2;
    	int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    	build(start, mid, leftInd, arr);
    	build(mid + 1, end, rightInd, arr);
    	seg[ind].merge(seg[leftInd], seg[rightInd]);
    }
	
	void apply (int start, int end, int ind, Update &u) {
		if(start != end) {
			lazy[ind] = 1;
			updates[ind].combine(start, end, u);
		}
		u.apply(start, end, seg[ind]);
	}
	
	void pushdown (int start, int end, int ind) {
		if(!lazy[ind]) return;
		int mid = (start + end) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		apply(start, mid, leftInd, updates[ind]);
		apply(mid + 1, end, rightInd, updates[ind]);
		updates[ind] = Update();
		lazy[ind] = 0;
	}
	
	Node query (int start, int end, int ind, int left, int right) {
		if(start > right || end < left) {
			return Node();
		}
		if(start >= left && end <= right) {
			pushdown(start, end, ind);
			return seg[ind];
		}
		pushdown(start, end, ind);
		int mid = (start + end) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		Node res;
		Node leftItem = query(start, mid, leftInd, left, right);
		Node rightItem = query(mid + 1, end, rightInd, left, right);
		res.merge(leftItem, rightItem);
		return res;
	}
	
	void update (int start, int end, int ind, int left, int right, Update &u) {
		if(start > right || end < left) return;
		if(start >= left && end <= right) {
			apply(start, end, ind, u);
			return;
		}
		pushdown(start, end, ind);
		int mid = (start + end) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		update(start, mid, leftInd, left, right, u);
		update(mid + 1, end, rightInd, left, right, u);
		seg[ind].merge(seg[leftInd], seg[rightInd]);
	}
	
public:
	LazySegmentTree () {
		
	}
    
    LazySegmentTree (int n) {
    	size = n;
    	seg.resize(4 * size + 1);
    	lazy.resize(4 * size + 1);
    	updates.resize(4 * size + 1);
    }
    
    LazySegmentTree (vector<T> &arr) {
    	size = arr.size();
    	seg.resize(4 * size + 1);
    	lazy.resize(4 * size + 1);
    	updates.resize(4 * size + 1);
    	build(arr);
    }
    
    void build (vector<T> &arr) {
    	build(0, size - 1, 0, arr);
    }
    
    Node query (int left, int right) {
    	return query(0, size - 1, 0, left, right);
    }
    
    void update (int left, int right, int value) {
    	Update u = Update(value);
    	return update(0, size - 1, 0, left, right, u);
    }
};
 
struct Node {
    long long sum;
    long long mx, mn;
    
    Node () : sum(0), mx(-MX), mn(MX) {}
    Node (int val) : sum(val), mx(val), mn(val) {}
    
    void merge (Node &left, Node &right) {
    	// sum = left.sum + right.sum;
    	mx = max(left.mx, right.mx);
    	mn = min(left.mn, right.mn);
    }
};
 
struct Update {
	long long val;
	
	Update () : val(0) {}
	Update (int v) : val(v) {}
	
	void apply (int start, int end, Node &node) {
		int len = end - start + 1;
		node.sum += len * val;
		node.mn += val;
		node.mx += val;
	}
	
	void combine (int start, int end, Update &u) {
		val += u.val;
	}
};
 
void solve() {
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	LazySegmentTree<int> sg(a);
	
	while(q--) {
		
		int type;
		cin >> type;
		
		if (type == 1) {
			int left, right, value;
			cin >> left >> right >> value;
			left--, right--;
			sg.update(left, right, value);
		}
		
		else {
			int index;
			cin >> index;
			index--;
			Node res = sg.query(index, index);
			cout << res.mx << endl;
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
