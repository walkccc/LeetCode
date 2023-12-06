class Solution {
  public int stoneGameV(int[] stoneValue) {
    final int n = stoneValue.length;
    // dp[i][j] := the maximum score that Alice can obtain from stoneValue[i..j]
    dp = new int[n][n];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, Integer.MIN_VALUE));
    prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = stoneValue[i] + prefix[i];

    return stoneGameV(stoneValue, 0, n - 1);
  }

  private int[][] dp;
  private int[] prefix;

  private int stoneGameV(int[] stoneValue, int i, int j) {
    if (i == j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    // Try all the possible partitions.
    for (int p = i; p < j; ++p) {
      // sum(stoneValue[i..p])
      final int leftSum = prefix[p + 1] - prefix[i];
      final int throwRight = leftSum + stoneGameV(stoneValue, i, p);
      // sum(stoneValue[p + 1..j])
      final int rightSum = prefix[j + 1] - prefix[p + 1];
      final int throwLeft = rightSum + stoneGameV(stoneValue, p + 1, j);
      if (leftSum < rightSum) // Bob throws the right row.
        dp[i][j] = Math.max(dp[i][j], throwRight);
      else if (leftSum > rightSum) // Bob throws the left row.
        dp[i][j] = Math.max(dp[i][j], throwLeft);
      else // Alice decides which row to throw.
        dp[i][j] = Math.max(dp[i][j], Math.max(throwLeft, throwRight));
    }

    return dp[i][j];
  }
}
