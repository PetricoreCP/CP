struct Dsu {
    int n, cnt;
    vector<int> parent, sz;
    Dsu(int n) : n(n), cnt(n) {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        int root = u;
        while (parent[root] != root) {
            root = parent[root];
        }
        while (parent[u] != u) {
            int tmp = parent[u];
            parent[u] = root;
            u = tmp;
        }
        return root;
    }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);   
        if (u == v) {
            return false;
        }
        if (sz[u] < sz[v]) {
            swap(u, v);
        }
        sz[u] += sz[v];
        parent[v] = u;
        cnt --;
        return true;
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    int getSize(int u) {
        return sz[find(u)];
    }
    int countComponents() {
        return cnt;
    }
};
