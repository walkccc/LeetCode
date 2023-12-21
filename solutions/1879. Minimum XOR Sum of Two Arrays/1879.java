class Solution {
  public int minimumXORSum(int[] nums1, int[] nums2) {
    int[] dp = new int[1 << nums2.length];
    Arrays.fill(dp, Integer.MAX_VALUE);
    return dfs(nums1, nums2, dp, 0, 0);
  }

  private int dfs(int[] nums1, int[] nums2, int[] dp, int i, int mask) {
    if (i == nums1.length)
      return 0;
    if (dp[mask] < Integer.MAX_VALUE)
      return dp[mask];

    for (int j = 0; j < nums2.length; ++j)
      if ((mask >> j & 1) == 0)
        dp[mask] = Math.min(dp[mask], //
                            (nums1[i] ^ nums2[j]) + dfs(nums1, nums2, dp, i + 1, mask | 1 << j));

    return dp[mask];
  }
}
