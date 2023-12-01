class Solution {
  public int countPartitions(int[] nums, int k) {
    final int kMod = 1_000_000_007;
    final long sum = Arrays.stream(nums).asLongStream().sum();
    long ans = modPow(2, nums.length, kMod); // 2^n % kMod
    long[] dp = new long[k + 1];
    dp[0] = 1;

    for (final int num : nums)
      for (int i = k; i >= num; --i) {
        dp[i] += dp[i - num];
        dp[i] %= kMod;
      }

    // Substract the cases that're not satisfied.
    for (int i = 0; i < k; ++i)
      if (sum - i < k) // Both group1 and group2 < k.
        ans -= dp[i];
      else
        ans -= dp[i] * 2;

    return (int) ((ans % kMod + kMod) % kMod);
  }

  private int modPow(int x, int n, int kMod) {
    int res = 1;
    for (int i = 0; i < n; ++i)
      res = res * x % kMod;
    return res;
  }
}
