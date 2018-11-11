#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

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

struct Edge {
    int s, f, w, n;
    Edge (): s(-1), f(-1), w(INF), n(-1) {}
    Edge (int _s, int _f, int _w, int _n): s(_s), f(_f), w(_w), n(_n) {}

    friend bool operator < (Edge a, Edge b) {
        return a.w < b.w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e(m);
    DSU v(n);

    for (int i = 0; i < m; i++) {
        cin >> e[i].s >> e[i].f >> e[i].w;
        --e[i].s; --e[i].f;
        e[i].n = i;
    }

    sort(e.begin(), e.end());

    vector<Edge> ostov;

    for (int i = 0; i < m; i++) {
        if (!v.are_united(e[i].s, e[i].f)) {
            ostov.push_back(e[i]);
            v.unite(e[i].s, e[i].f);
        }
    }

    // вывод ответа
}
