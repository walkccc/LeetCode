class Solution {
  public int combinationSum4(int[] nums, int target) {
    // dp[i] := # of combinations that add up to i
    int[] dp = new int[target + 1];
    dp[0] = 1;

    for (int i = 0; i <= target; ++i)
      for (final int num : nums)
        if (i >= num)
          dp[i] += dp[i - num];

    return dp[target];
  }
}
