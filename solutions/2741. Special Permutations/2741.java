class Solution {
  public int specialPerm(int[] nums) {
    final int n = nums.length;
    final int maxMask = 1 << n;
    int ans = 0;
    // dp[i][j] := the number of special permutations, where the previous number
    // is nums[i] and bitmask j represents the used numbers
    dp = new int[n][maxMask];

    for (int i = 0; i < n; ++i) {
      ans += specialPerm(nums, i, 1 << i, maxMask);
      ans %= kMod;
    }

    return ans;
  }

  private static final int kMod = 1_000_000_007;
  private int[][] dp;

  private int specialPerm(int[] nums, int prev, int mask, int maxMask) {
    if (mask == maxMask - 1)
      return 1;
    if (dp[prev][mask] != 0)
      return dp[prev][mask];

    int res = 0;

    for (int i = 0; i < nums.length; ++i) {
      if ((mask >> i & 1) == 1)
        continue;
      if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) {
        res += specialPerm(nums, i, mask | 1 << i, maxMask);
        res %= kMod;
      }
    }

    return dp[prev][mask] = res;
  }
}
