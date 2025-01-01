class Solution {
  public int sumOfPower(int[] nums, int k) {
    Integer[][] mem = new Integer[nums.length][k + 1];
    return sumOfPower(nums, 0, k, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of subsequences in nums[i..n) that sums to j.
  private int sumOfPower(int[] nums, int i, int j, Integer[][] mem) {
    if (j == 0)
      // For each of the remaining number, we can either pick it or skip it.
      return (int) modPow(2, nums.length - i);
    if (i == nums.length || j < 0)
      return 0;
    if (mem[i][j] != null)
      return mem[i][j];
    // 1. Include nums[i] in the subsequence and pick it.
    // 2. Include nums[i] in the subsequence and skip it.
    // 3. Exclude nums[i] in the subsequence.
    return mem[i][j] = (int) ((sumOfPower(nums, i + 1, j - nums[i], mem) + //
                               2L * sumOfPower(nums, i + 1, j, mem)) %
                              kMod);
  }

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
}
