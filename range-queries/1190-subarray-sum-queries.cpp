
#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#endif
 
// === Segment Tree ===
struct Node;
struct Update;
 
template <typename T = int, typename Node = Node, typename Update = Update>
class SegmentTree {
private: 
	int size = 0;
	vector<Node> seg;
	
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
	
	Node query (int start, int end, int ind, int left, int right) {
		if(start > right || end < left) {
			return Node();
		}
		if(start >= left && end <= right) {
			return seg[ind];
		}
		int mid = (start + end) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		Node res;
		Node leftItem = query(start, mid, leftInd, left, right);
		Node rightItem = query(mid + 1, end, rightInd, left, right);
		res.merge(leftItem, rightItem);
		return res;
	}
	
	void update (int start, int end, int ind, int index, Update &u) {
		if(start == end) {
			u.apply(seg[ind]);
			return;
		}
		int mid = (start + end) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		if(index <= mid) update(start, mid, leftInd, index, u);
		else update(mid + 1, end, rightInd, index, u);
		seg[ind].merge(seg[leftInd], seg[rightInd]);
	}
	
public:
	SegmentTree () {
		
	}
    
    SegmentTree (int n) {
    	size = n;
    	seg.resize(4 * size + 1);
    	vector<T> arr(n, 0);
    	build(arr);
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
    
    void update (int index, long long value) {
    	Update u = Update(value);
    	return update(0, size - 1, 0, index, u);
    }
};
 
struct Node {
    long long sum, mx, mn, pref, suff, mxSum;
    
    Node () : sum(0), mx(-1e17), mn(1e17), pref(0), suff(0), mxSum(0) {}
    Node (long long val) : sum(val), mx(val), mn(val) {
		pref = suff = mxSum = max(0LL, val);
	}
    
    void merge (Node &left, Node &right) {
    	sum = left.sum + right.sum;
    	mx = max(left.mx, right.mx);
    	mn = min(left.mn, right.mn);
		pref = max(left.pref, left.sum + right.pref);
		suff = max(right.suff, right.sum + left.suff);
		mxSum = max({left.mxSum, right.mxSum, left.suff + right.pref});
    }
};
 
struct Update {
	long long val;
	
	Update () : val(0) {}
	Update (long long v) : val(v) {}
	
	void apply (Node &node) {
		node = Node(val);
	}
};
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
	int n, q;
	cin >> n >> q;
 
	vector<int> a(n);
	for (int &x: a) cin >> x;
 
	SegmentTree sg(a);
 
	while (q--) {
		int index, value;
		cin >> index >> value;
		index--;
 
		sg.update(index, value);
 
		long long res = sg.query(0, n - 1).mxSum;
		cout << res << endl;
	}
	
	return 0;
}
