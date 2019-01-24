#include <iostream>
#include <vector>
using namespace std;
int n;
vector<long long> a, b;

void add(int i, int x) {
    for (; i <= n; i = (i | (i - 1)) + 1) {
        b[i] += x;
    }
}

void set(int i, int x) {
    int to_add = x - a[i];
    a[i] = x;
    add(i, to_add);
}

// [1,r]
long long get_sum(int r) {
    long long res = 0;
    for (; r > 0; r &= (r - 1)) {
//        cerr << r << endl;
        res += b[r];
    }
    return res;
}

// [l,r]
long long get_sum(int l, int r) {
    return get_sum(r) - get_sum(l - 1);
}

int main() {
    int m;
    cin >> n >> m;
    a.resize(n + 1); b.resize(n + 1);

    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            set(i, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get_sum(l, r) << endl;
        }
    }
}
