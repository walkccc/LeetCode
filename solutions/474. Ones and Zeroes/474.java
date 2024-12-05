class Solution {
  public int findMaxForm(String[] strs, int m, int n) {
    // dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    // available
    int[][] dp = new int[m + 1][n + 1];

    for (final String s : strs) {
      final int zeros = (int) s.chars().filter(c -> c == '0').count();
      final int ones = (int) s.length() - zeros;
      for (int i = m; i >= zeros; --i)
        for (int j = n; j >= ones; --j)
          dp[i][j] = Math.max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }

    return dp[m][n];
  }
}
