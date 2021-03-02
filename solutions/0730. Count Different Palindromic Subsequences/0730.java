class Solution {
  public int countPalindromicSubsequences(String S) {
    final int kMod = (int) 1e9 + 7;
    final int n = S.length();

    // dp[i][j] := # of different non-empty palindromic subseqs in S[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        if (S.charAt(i) == S.charAt(j)) {
          int lo = i + 1;
          int hi = j - 1;
          while (lo <= hi && S.charAt(lo) != S.charAt(i))
            ++lo;
          while (lo <= hi && S.charAt(hi) != S.charAt(i))
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
        dp[i][j] = (int) (((long) dp[i][j] + kMod) % kMod);
      }

    return dp[0][n - 1];
  }
}
