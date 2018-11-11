// Disjoint Set Union
struct DSU {
    vector<int> p, w;

    DSU(int n): p(n), w(n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            w[i] = 1;
        }
    }

    int get_head(int v) {
        if (p[v] == v)
            return v;

        return p[v] = get_head(p[v]);
    }

    bool are_united(int a, int b) {
        return get_head(a) == get_head(b);
    }

    void unite(int a, int b) {
        a = get_head(a);
        b = get_head(b);

        if (w[a] < w[b]) {
            p[a] = b;
            w[b] += w[a];
        } else {
            p[b] = a;
            w[a] += w[b];
        }
    }
};
