class Solution {
  public int specialPerm(int[] nums) {
    final int n = nums.length;
    final int maxMask = 1 << n;
    int ans = 0;
    int[][] mem = new int[n][maxMask];

    for (int i = 0; i < n; ++i) {
      ans += specialPerm(nums, i, 1 << i, maxMask, mem);
      ans %= kMod;
    }

    return ans;
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of special permutations, where the previous number is
  // nums[i] and `mask` is the bitmask of the used numbers.
  private int specialPerm(int[] nums, int prev, int mask, int maxMask, int[][] mem) {
    if (mask == maxMask - 1)
      return 1;
    if (mem[prev][mask] != 0)
      return mem[prev][mask];

    int res = 0;

    for (int i = 0; i < nums.length; ++i) {
      if ((mask >> i & 1) == 1)
        continue;
      if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) {
        res += specialPerm(nums, i, mask | 1 << i, maxMask, mem);
        res %= kMod;
      }
    }

    return mem[prev][mask] = res;
  }
}
