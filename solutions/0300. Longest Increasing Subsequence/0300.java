class Solution {
  public int lengthOfLIS(int[] nums) {
    if (nums.length == 0)
      return 0;

    // dp[i] := length of LIS ending at nums[i]
    int[] dp = new int[nums.length];
    Arrays.fill(dp, 1);

    for (int i = 1; i < nums.length; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          dp[i] = Math.max(dp[i], dp[j] + 1);

    return Arrays.stream(dp).max().getAsInt();
  }
}
