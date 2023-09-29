#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

// === Segment Tree ===
struct Node;
struct Update;

template <typename T, typename Node = Node, typename Update = Update>
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
    	vector<T> arr (n, 0);
    	build (arr);
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
    	Update u = Update(value);
    	return update(0, size - 1, 0, index, u);
    }
};

struct Node {
    long long sum;
    int mx, mn;
    
    Node () : sum(0), mx(-1e9), mn(1e9) {}
    Node (int val) : sum(val), mx(val), mn(val) {}
    
    void merge (Node &left, Node &right) {
    	sum = left.sum + right.sum;
    	mx = max(left.mx, right.mx);
    	mn = min(left.mn, right.mn);
    }
};

struct Update {
	int val;
	
	Update () : val(0) {}
	Update (int v) : val(v) {}
	
	void apply (Node &node) {
		node.sum = val;
		node.mn = val;
		node.mx = val;
	}
};

void solve() {
	
	int n, q;
	cin >> n >> q;
	
	vector<int> a (n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<int> adj[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> tree;
	
	function<void(int,int)> dfs = [&] (int node, int par) {
		tree.push_back (node);
		for (int child : adj[node]) if (child != par) {
			dfs (child, node);
		}
		tree.push_back (node);
	};
	
	dfs(1, 0);
	
	vector<vector<int>> index (2 * n);
	for (int i = 0; i < 2 * n; i++) {
		int node = tree[i];
		index[node].push_back(i);
	}
	
	SegmentTree<int> sg (2 * n);
	for (int i = 1; i <= n; i++) {
		sg.update (index[i][0], a[i]);
	}
	
	while (q--) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int node, val;
			cin >> node >> val;
			int ind = index[node][0];
			sg.update (ind, val);
		}
		
		else {
			int node;
			cin >> node;
			int left = index[node][0], right = index[node][1];
			long long ans = sg.query (left, right).sum;
			cout << ans << endl;
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
