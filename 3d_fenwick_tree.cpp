#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;
int n;
vector<vector<vector<ll>>> a, b;

void add(int val, int x, int y, int z) {
    for (int i = x; i <= n; i = (i | (i - 1)) + 1)
        for (int j = y; j <= n; j = (j | (j - 1)) + 1)
            for (int k = z; k <= n; k = (k | (k - 1)) + 1)
                b[i][j][k] += val;
}

ll get_sum(int x, int y, int z) {
    long long res = 0;
    for (int i = x; i > 0; i &= (i - 1))
        for (int j = y; j > 0; j &= (j - 1))
            for (int k = z; k > 0; k &= (k - 1))
                res += b[i][j][k];

    return res;
}

ll get_sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    ll ans = get_sum(x2, y2, z2);
    ans -= get_sum(x1, y2, z2);
    ans -= get_sum(x2, y1, z2);
    ans += get_sum(x1, y1, z2);

    ans -= get_sum(x2, y2, z1);
    ans += get_sum(x1, y2, z1);
    ans += get_sum(x2, y1, z1);
    ans -= get_sum(x1, y1, z1);
    return ans;
}

int main() {
    ifstream in("stars.in");
    ofstream out("stars.out");

    in >> n;
    ++n;
    a = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(n)));
    b = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(n)));
    --n;

    int c = 0;
    while (c != 3) {
        in >> c;
        if (c == 1) {
            int k, x, y, z;
            in >> x >> y >> z >> k;
            ++x; ++y; ++z;
            add(k, x, y, z);
        } else if (c == 2) {
            int x1, y1, z1, x2, y2, z2;
            in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ++x2; ++y2; ++z2;
            out << get_sum(x1, y1, z1, x2, y2, z2) << endl;
        }
    }
}
