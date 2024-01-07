#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MX = 1e9;
 
// === Segment Tree ===
 
struct Item{
    long long sum, mx, mn;
};
 
template <typename T>
class SegmentTree{
private: 
	
	int size = 0;
	vector<Item> seg;
	
    Item NEUTRAL_ELEMENT = {0, -MX, MX};
	
	Item single (int val) {
		return {val, val, val};
	}
	
	Item merge (Item left, Item right) {
		Item node = NEUTRAL_ELEMENT;
		node.sum = left.sum + right.sum;
		node.mn = min(left.mn, right.mn);
		node.mx = max(left.mx, right.mx);
		return node;
	}
	
    void build (int low, int high, int ind, vector<T> &arr) {
    	if(low == high) {
    		seg[ind] = single(arr[low]);
    		return;
    	}
    	int mid = (low + high) / 2;
    	int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
    	build(low, mid, leftInd, arr);
    	build(mid + 1, high, rightInd, arr);
    	seg[ind] = merge(seg[leftInd], seg[rightInd]);
    }
	
	Item query (int low, int high, int ind, int left, int right) {
		if(low > right || high < left) {
			return NEUTRAL_ELEMENT;
		}
		if(low >= left && high <= right) {
			return seg[ind];
		}
		int mid = (low + high) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		Item leftItem = query(low, mid, leftInd, left, right);
		Item rightItem = query(mid + 1, high, rightInd, left, right);
		return merge(leftItem, rightItem);
	}
	
	void update (int low, int high, int ind, int index, int value) {
		if(low == high) {
			seg[ind] = single(value);
			return;
		}
		int mid = (low + high) / 2;
		int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;
		if(index <= mid) update(low, mid, leftInd, index, value);
		else update(mid + 1, high, rightInd, value);
		seg[ind] = merge(seg[leftInd], seg[rightInd]);
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
    
    Item query (int left, int right) {
    	return query(0, size - 1, 0, left, right);
    }
    
    void update (int index, int value) {
    	return update(0, size - 1, 0, index, value);
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
		
		int start, end;
		cin >> start >> end;
		start--, end--;
		
		long long sum = sg.query(start, end).sum;
		cout << sum << endl;
	}
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
