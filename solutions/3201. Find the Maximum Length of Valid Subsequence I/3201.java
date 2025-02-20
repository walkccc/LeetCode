class Solution {
  public int maximumLength(int[] nums) {
    // dp[i][j] := the maximum length of a valid subsequence, where the last
    // number mod 2 equal to i and the next desired number mod 2 equal to j
    int[][] dp = new int[k][k];

    // Extend the pattern xyxyxy...xy.
    for (final int x : nums)
      for (int y = 0; y < 2; ++y)
        dp[x % 2][y] = dp[y][x % 2] + 1;

    return Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
  }
}
