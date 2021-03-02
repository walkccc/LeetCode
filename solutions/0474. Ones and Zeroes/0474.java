class Solution {
  public int findMaxForm(String[] strs, int m, int n) {
    // dp[i][j] := max size of the subset given i 0's and j 1's are available
    int[][] dp = new int[m + 1][n + 1];

    for (final String s : strs) {
      final int count0 = (int) s.chars().filter(c -> c == '0').count();
      final int count1 = (int) s.length() - count0;
      for (int i = m; i >= count0; --i)
        for (int j = n; j >= count1; --j)
          dp[i][j] = Math.max(dp[i][j], dp[i - count0][j - count1] + 1);
    }

    return dp[m][n];
  }
}
