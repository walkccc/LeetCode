class Solution {
  public boolean PredictTheWinner(int[] nums) {
    final int n = nums.length;
    int[] dp = nums.clone();

    for (int d = 1; d < n; ++d)
      for (int j = n - 1; j - d >= 0; --j) {
        final int i = j - d;
        dp[j] = Math.max(nums[i] - dp[j],      // Pick the leftmost number.
                         nums[j] - dp[j - 1]); // Pick the rightmost number.
      }

    return dp[n - 1] >= 0;
  }
}
