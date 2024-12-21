class Solution {
  public int maxSubArray(int[] nums) {
    // dp[i] := the maximum sum subarray ending in i
    int[] dp = new int[nums.length];

    dp[0] = nums[0];
    for (int i = 1; i < nums.length; ++i)
      dp[i] = Math.max(nums[i], dp[i - 1] + nums[i]);

    return Arrays.stream(dp).max().getAsInt();
  }
}
