vector<int> z(string s) {
    int n = s.size();
    int l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (l <= i && i <= r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }

    return z;
}