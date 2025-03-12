class Solution {
  public int[] maxHammingDistances(int[] nums, int m) {
    final int MAX_MASK = 1 << m;
    int[] ans = new int[nums.length];
    // dp[i] := the maximum hamming distance from i to any number in `nums`
    int[] dp = new int[MAX_MASK];
    Arrays.fill(dp, Integer.MIN_VALUE);

    for (final int num : nums)
      dp[num] = 0;

    for (int bit = 0; bit < m; ++bit) {
      int[] newDp = new int[MAX_MASK];
      for (int mask = 0; mask < MAX_MASK; ++mask)
        newDp[mask] = Math.max(dp[mask], dp[mask ^ (1 << bit)] + 1);
      dp = newDp;
    }

    for (int i = 0; i < nums.length; ++i)
      ans[i] = dp[nums[i]];

    return ans;
  }
}
