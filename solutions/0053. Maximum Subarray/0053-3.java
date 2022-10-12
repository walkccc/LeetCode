class Solution {
  public int maxSubArray(int[] nums) {
    // dp[i] := max sum subarray ending w/ nums[i]
    int[] dp = new int[nums.length];

    for (int i = 0; i < nums.length; ++i)
      if (i > 0 && dp[i - 1] > 0)
        dp[i] = dp[i - 1] + nums[i];
      else
        dp[i] = nums[i];

    return Arrays.stream(dp).max().getAsInt();
  }
}
