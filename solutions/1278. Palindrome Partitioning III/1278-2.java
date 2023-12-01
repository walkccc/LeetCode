class Solution {
  public int palindromePartition(String s, int K) {
    final int n = s.length();
    // dp[i][k] := the minimum cost to make k palindromes by s[0..i)
    int[][] dp = new int[n + 1][K + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, n));
    // cost[i][j] := the minimum cost to make s[i..j] palindrome
    int[][] cost = new int[n][n];

    for (int d = 1; d < n; ++d)
      for (int i = 0, j = d; j < n; ++i, ++j)
        cost[i][j] = (s.charAt(i) == s.charAt(j) ? 0 : 1) + cost[i + 1][j - 1];

    for (int i = 1; i <= n; ++i)
      dp[i][1] = cost[0][i - 1];

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[i][k] = Math.min(dp[i][k], dp[j][k - 1] + cost[j][i - 1]);

    return dp[n][K];
  }
}
