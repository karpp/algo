vector<int> prefix(string s) {
    auto n = s.size();

    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        int cur = ans[i - 1];

        while (cur > 0 && s[cur] != s[i])
            cur = ans[cur - 1];

        if (s[i] == s[cur])
            ans[i] = cur + 1;
    }

    return ans;
}