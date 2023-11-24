class Solution {
 public:
  int countPartitions(vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    long ans = modPow(2, nums.size(), kMod);  // 2^n % kMod
    vector<long> dp(k + 1);
    dp[0] = 1;

    for (const int num : nums)
      for (int i = k; i >= num; --i) {
        dp[i] += dp[i - num];
        dp[i] %= kMod;
      }

    // Minus cases that're not satisfied.
    for (int i = 0; i < k; ++i)
      if (sum - i < k)  // Both group1 and group2 < k
        ans -= dp[i];
      else
        ans -= dp[i] * 2;

    return (ans % kMod + kMod) % kMod;
  }

 private:
  int modPow(int x, int n, int kMod) {
    int res = 1;
    for (int i = 0; i < n; ++i)
      res = res * x % kMod;
    return res;
  }
};
