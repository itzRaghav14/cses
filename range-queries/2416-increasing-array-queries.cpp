#include <bits/stdc++.h>
using namespace std;

// === Lazy Segment Tree ===
struct Node;
struct Update;

template <typename T = long long, typename Node = Node, typename Update = Update>
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
        vector<T> arr (n, 0);
        build(arr);
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
    
    void update (int left, int right, long long value) {
        Update u = Update(value);
        return update(0, size - 1, 0, left, right, u);
    }
};

struct Node {
    long long sum, targetSum;
    
    Node () : sum(0), targetSum(0) {}
    Node (long long sum) : sum(sum), targetSum(sum) {}
    
    void merge (Node &left, Node &right) {
        sum = left.sum + right.sum;
        targetSum = left.targetSum + right.targetSum;
    }

    long long getCost() {
        return targetSum - sum;
    }
};

struct Update {
    long long val;
    
    Update () : val(0) {}
    Update (long long v) : val(v) {}
    
    void apply (int start, int end, Node &node) {
        int len = end - start + 1;
        node.targetSum = len * val;
    }
    
    void combine (int start, int end, Update &u) {
        val = u.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x: a) cin >> x;

    vector<vector<array<int,2>>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[l].push_back({r, i});
    }

    vector<int> stk;
    LazySegmentTree st(a);
    vector<long long> ans(q);

    for (int l = n - 1; l >= 0; l--) {
        while (!stk.empty() && a[stk.back()] < a[l]) stk.pop_back();
        int next = stk.empty() ? n : stk.back();
        stk.push_back(l);

        st.update(l, next - 1, a[l]);

        for (auto [r, i]: queries[l]) {
            ans[i] = st.query(l, r).getCost();
        }
    }

    for (auto &x: ans) cout << x << "\n";
    
    return 0;
}
