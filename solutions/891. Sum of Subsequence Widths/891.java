class Solution {
  public int sumSubseqWidths(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    long ans = 0;
    long exp = 1;

    Arrays.sort(nums);

    for (int i = 0; i < n; ++i, exp = exp * 2 % kMod) {
      ans += (nums[i] - nums[n - 1 - i]) * exp;
      ans %= kMod;
    }

    return (int) ans;
  }
}
