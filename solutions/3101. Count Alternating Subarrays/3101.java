class Solution {
  public long countAlternatingSubarrays(int[] nums) {
    // dp[i] := the number of alternating subarrays ending in index i
    long[] dp = new long[nums.length];
    Arrays.fill(dp, 1);

    for (int i = 1; i < nums.length; ++i)
      if (nums[i] != nums[i - 1])
        dp[i] += dp[i - 1];

    return Arrays.stream(dp).sum();
  }
}
