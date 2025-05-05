class Solution {
  public int sumOfPower(int[] nums) {
    final int MOD = 1_000_000_007;
    long ans = 0;
    long sum = 0;

    Arrays.sort(nums);

    for (final int num : nums) {
      ans = (ans + (num + sum) * num % MOD * num % MOD) % MOD;
      sum = (sum * 2 + num) % MOD;
    }

    return (int) ans;
  }
}
