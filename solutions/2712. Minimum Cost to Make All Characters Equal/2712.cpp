class Solution {
 public:
  long long minimumCost(string s) {
    const int n = s.length();
    long long ans = 0;

    for (int i = 1; i < n; ++i)
      if (s[i] != s[i - 1])
        // Invert s[0..i - 1] or s[i..n - 1].
        ans += min(i, n - i);

    return ans;
  }
};
