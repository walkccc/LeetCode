class Solution {
  public int numberOfArithmeticSlices(int[] nums) {
    final int n = nums.length;
    if (n < 3)
      return 0;

    int[] dp = new int[n]; // dp[i] := the number of arithmetic slices ends in nums[i]

    for (int i = 2; i < n; ++i)
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        dp[i] += dp[i - 1] + 1;

    return Arrays.stream(dp).sum();
  }
}
