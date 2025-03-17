// Binary Tree: Segment Tree
// Range Query && Update Value -> O(log2(N))
// Parent[tree[i]] -> tree[i >> 1]
// Children[tree[i]] -> tree[i << 1] && tree[(i << 1) + 1]
template<typename T>
struct SegTree {
    int N = 1;
    vector<T> tree;
    SegTree(const vector<T>& v) {
        while (N < v.size()) N <<= 1;
        // Default value 0
        tree.resize(N << 1, 0);
        for (int i = 0; i < v.size(); i ++) {
            tree[N + i] = v[i];
        } 
        // Build the tree using query operation
        for (int i = N - 1; i > 0; i --) {
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
    }
    // query: [l, r] 0-indexed
    T query(int l, int r) {
        l += N;
        r += N;
        T res = 0;
        while (l <= r) {
            if (l & 1) {
                res += tree[l];
                l ++;
            }
            if (!(r & 1)) {
                res += tree[r];
                r --;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    // update: tree[i] to x 0-indexed
    void update(int i, T x) {
        i += N;
        tree[i] = x;
        // Update the parents using query operation
        while ((i >> 1) > 0) {
            i >>= 1;
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
    }
};
