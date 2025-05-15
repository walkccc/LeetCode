class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    const int n = s.length();
    vector<int> ans(n);
    int prev = -n;

    for (int i = 0; i < n; ++i) {
      if (s[i] == c)
        prev = i;
      ans[i] = i - prev;
    }

    for (int i = prev - 1; i >= 0; --i) {
      if (s[i] == c)
        prev = i;
      ans[i] = min(ans[i], prev - i);
    }

    return ans;
  }
};
