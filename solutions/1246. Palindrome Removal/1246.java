class Solution {
  public int minimumMoves(int[] arr) {
    final int n = arr.length;
    // dp[i][j] := the minimum number of moves to remove all numbers from arr[i..j]
    int[][] dp = new int[n][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int i = 0; i + 1 < n; ++i)
      dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;

    for (int d = 2; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        // Remove arr[i] and arr[j] within the move of removing
        // arr[i + 1..j - 1]
        if (arr[i] == arr[j])
          dp[i][j] = dp[i + 1][j - 1];
        // Try all the possible partitions.
        for (int k = i; k < j; ++k)
          dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }

    return dp[0][n - 1];
  }
}
