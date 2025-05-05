class Solution {
  public int minOperations(String initial, String target) {
    final int m = initial.length();
    final int n = target.length();
    // dp[i][j] := the length of LCS(initial[0..i), target[0..j))
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (initial.charAt(i - 1) == target.charAt(j - 1))
          dp[i][j] = 1 + dp[i - 1][j - 1];

    final int maxCommonLength = Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
    return m + n - 2 * maxCommonLength;
  }
}
