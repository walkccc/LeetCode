class Solution {
  public int sumSubseqWidths(int[] nums) {
    final int kMod = (int) 1e9 + 7;
    final int n = nums.length;
    long ans = 0;
    long exp = 1;

    Arrays.sort(nums);

    for (int i = 0; i < n; ++i, exp = exp * 2 % kMod) {
      ans += (nums[i] - nums[n - i - 1]) * exp;
      ans %= kMod;
    }

    return (int) ans;
  }
}
