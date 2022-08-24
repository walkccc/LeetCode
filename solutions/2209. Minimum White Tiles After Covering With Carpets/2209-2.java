class Solution {
  public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
    final int n = floor.length();
    // dp[i][j] := min # of visible white tiles of floor[i:]
    // after covering at most j carpets
    int[][] dp = new int[n + 1][numCarpets + 1];

    for (int i = n - 1; i >= 0; --i)
      dp[i][0] = floor.charAt(i) - '0' + dp[i + 1][0];

    for (int i = n - 1; i >= 0; --i)
      for (int j = 1; j <= numCarpets; ++j) {
        final int cover = i + carpetLen < n ? dp[i + carpetLen][j - 1] : 0;
        final int skip = floor.charAt(i) - '0' + dp[i + 1][j];
        dp[i][j] = Math.min(cover, skip);
      }

    return dp[0][numCarpets];
  }
}
