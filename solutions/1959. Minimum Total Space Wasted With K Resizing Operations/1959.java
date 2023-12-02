class Solution {
  public int minSpaceWastedKResizing(int[] nums, int k) {
    // dp[i][k] := the minimum space wasted for nums[i..n) if you can resize k times
    dp = new Integer[nums.length][k + 1];
    return minSpaceWasted(nums, 0, k);
  }

  private static final int kMax = 200_000_000;
  private Integer[][] dp;

  private int minSpaceWasted(int[] nums, int i, int k) {
    if (i == nums.length)
      return 0;
    if (k == -1)
      return kMax;
    if (dp[i][k] != null)
      return dp[i][k];

    int ans = kMax;
    int sum = 0;
    int maxNum = nums[i];

    for (int j = i; j < nums.length; ++j) {
      sum += nums[j];
      maxNum = Math.max(maxNum, nums[j]);
      final int wasted = maxNum * (j - i + 1) - sum;
      ans = Math.min(ans, minSpaceWasted(nums, j + 1, k - 1) + wasted);
    }

    return dp[i][k] = ans;
  }
}
