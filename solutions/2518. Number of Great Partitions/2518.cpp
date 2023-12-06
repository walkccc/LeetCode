class Solution {
 public:
  int countPartitions(vector<int>& nums, int k) {
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    long ans = modPow(2, nums.size());
    vector<long> dp(k + 1);
    dp[0] = 1;

    for (const int num : nums)
      for (int i = k; i >= num; --i) {
        dp[i] += dp[i - num];
        dp[i] %= kMod;
      }

    // Substract the cases that're not satisfied.
    for (int i = 0; i < k; ++i)
      if (sum - i < k)  // Both group1 and group2 < k.
        ans -= dp[i];
      else
        ans -= dp[i] * 2;

    return (ans % kMod + kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
