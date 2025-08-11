class Solution {
  public boolean validPartition(int[] nums) {
    final int n = nums.length;
    // dp[i] := true if there's a valid partition for the first i numbers
    boolean[] dp = new boolean[n + 1];
    dp[0] = true;
    dp[2] = nums[0] == nums[1];

    for (int i = 3; i <= n; ++i)
      dp[i] = (dp[i - 2] && nums[i - 2] == nums[i - 1]) ||
              (dp[i - 3] && ((nums[i - 3] == nums[i - 2] && nums[i - 2] == nums[i - 1]) ||
                             (nums[i - 3] + 1 == nums[i - 2] && nums[i - 2] + 1 == nums[i - 1])));

    return dp[n];
  }
}
