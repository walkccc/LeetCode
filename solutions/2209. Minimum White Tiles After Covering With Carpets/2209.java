class Solution {
  public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
    // dp[i][j] := the minimum number of visible white tiles of floor[i..n)
    // after covering at most j carpets
    dp = new int[floor.length() + 1][numCarpets + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, kMax));
    return minimumWhiteTiles(floor, 0, numCarpets, carpetLen);
  }

  private static final int kMax = 1000;
  private int[][] dp;

  int minimumWhiteTiles(final String floor, int i, int j, int carpetLen) {
    if (j < 0)
      return kMax;
    if (i >= floor.length())
      return 0;
    if (dp[i][j] != kMax)
      return dp[i][j];
    return dp[i][j] =
               Math.min(minimumWhiteTiles(floor, i + carpetLen, j - 1, carpetLen),
                        minimumWhiteTiles(floor, i + 1, j, carpetLen) + floor.charAt(i) - '0');
  }
}
