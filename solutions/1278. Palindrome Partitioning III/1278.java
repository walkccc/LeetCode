class Solution {
  public int palindromePartition(String s, int k) {
    final int n = s.length();
    // dp[i][k] := min cost to make k palindromes by s[0..i)
    dp = new int[n + 1][k + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, n));
    // cost[i][j] := min cost to make s[i..j] palindrome
    cost = new int[n][n];

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s.charAt(i) == s.charAt(j) ? 0 : 1) + cost[i + 1][j - 1];

    return palindromePartition(n, k);
  }

  private int[][] dp;
  private int[][] cost;

  private int palindromePartition(int n, int k) {
    if (k == 1)
      return cost[0][n - 1];
    if (dp[n][k] < n)
      return dp[n][k];

    // try all possible partitions
    for (int i = k - 1; i < n; ++i)
      dp[n][k] = Math.min(dp[n][k], palindromePartition(i, k - 1) + cost[i][n - 1]);

    return dp[n][k];
  }
}
