class Solution {
  public int rob(int[] nums) {
    final int n = nums.length;
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];

    // dp[i] := the maximum money of robbing nums[0..i]
    int[] dp = new int[n];
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i)
      dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[n - 1];
  }
}
