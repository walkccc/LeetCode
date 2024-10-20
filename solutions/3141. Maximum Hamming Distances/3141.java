class Solution {
  public int[] maxHammingDistances(int[] nums, int m) {
    final int kMaxMask = 1 << m;
    int[] ans = new int[nums.length];
    // dp[i] := the maximum hamming distance from i to any number in `nums`
    int[] dp = new int[kMaxMask];
    Arrays.fill(dp, Integer.MIN_VALUE);

    for (final int num : nums)
      dp[num] = 0;

    for (int bit = 0; bit < m; ++bit) {
      int[] newDp = new int[kMaxMask];
      for (int mask = 0; mask < kMaxMask; ++mask)
        newDp[mask] = Math.max(dp[mask], dp[mask ^ (1 << bit)] + 1);
      dp = newDp;
    }

    for (int i = 0; i < nums.length; ++i)
      ans[i] = dp[nums[i]];

    return ans;
  }
}
