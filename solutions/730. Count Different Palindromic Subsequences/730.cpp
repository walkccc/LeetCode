class Solution {
 public:
  int countPalindromicSubsequences(string s) {
    constexpr int kMod = 1'000'000'007;
    const int n = s.length();
    // dp[i][j] := the number of different non-empty palindromic subsequences in
    // s[i..j]
    vector<vector<long>> dp(n, vector<long>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (s[i] == s[j]) {
          int lo = i + 1;
          int hi = j - 1;
          while (lo <= hi && s[lo] != s[i])
            ++lo;
          while (lo <= hi && s[hi] != s[i])
            --hi;
          if (lo > hi)
            dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
          else if (lo == hi)
            dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
          else
            dp[i][j] = dp[i + 1][j - 1] * 2 - dp[lo + 1][hi - 1];
        } else {
          dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        }
        dp[i][j] = (dp[i][j] + kMod) % kMod;
      }

    return dp[0][n - 1];
  }
};
