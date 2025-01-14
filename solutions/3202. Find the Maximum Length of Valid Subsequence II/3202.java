class Solution {
  // Similar to 3201. Find the Maximum Length of Valid Subsequence I
  public int maximumLength(int[] nums, int k) {
    // dp[i][j] := the maximum length of a valid subsequence, where the last
    // number mod k equal to i and the next desired number mod k equal to j
    int[][] dp = new int[k][k];

    // Extend the pattern xyxyxy...xy.
    for (final int x : nums)
      for (int y = 0; y < k; ++y)
        dp[x % k][y] = dp[y][x % k] + 1;

    return Arrays.stream(dp).flatMapToInt(Arrays::stream).max().getAsInt();
  }
}
