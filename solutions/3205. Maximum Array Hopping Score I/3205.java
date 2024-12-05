class Solution {
  public int maxScore(int[] nums) {
    final int n = nums.length;
    // dp[i] := the maximum score to jump from index i to n - 1
    int[] dp = new int[n];

    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j < n; ++j)
        // Jump from i to j, and then jump from j to n - 1.
        dp[i] = Math.max(dp[i], (j - i) * nums[j] + dp[j]);

    return dp[0];
  }
}
