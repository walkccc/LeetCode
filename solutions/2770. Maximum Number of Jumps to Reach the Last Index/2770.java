class Solution {
  public int maximumJumps(int[] nums, int target) {
    final int n = nums.length;
    // dp[i] := the maximum number of jumps to reach i from 0
    int[] dp = new int[n];
    Arrays.fill(dp, -1);
    dp[0] = 0;

    for (int j = 1; j < n; ++j)
      for (int i = 0; i < j; ++i)
        if (dp[i] != -1 && Math.abs(nums[j] - nums[i]) <= target)
          dp[j] = Math.max(dp[j], dp[i] + 1);

    return dp[n - 1];
  }
}
