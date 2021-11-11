class Solution {
 public:
  int countPalindromicSubsequences(string S) {
    constexpr int kMod = 1e9 + 7;
    const int n = S.length();

    // dp[i][j] := # of different non-empty palindromic subseqs in S[i..j]
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (S[i] == S[j]) {
          int lo = i + 1;
          int hi = j - 1;
          while (lo <= hi && S[lo] != S[i])
            ++lo;
          while (lo <= hi && S[hi] != S[i])
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
        dp[i][j] = (dp[i][j] + (long)kMod) % kMod;
      }

    return dp[0][n - 1];
  }
};
