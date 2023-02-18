class Solution {
 public:
  int countPartitions(vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    const long sum = accumulate(begin(nums), end(nums), 0L);
    long ans = myPow(2, nums.size(), kMod);  // 2^n % kMod
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
  // Returns base^k % kMod.
  int myPow(int base, int k, int kMod) {
    int res = 1;
    for (int i = 0; i < k; ++i)
      res = res * base % kMod;
    return res;
  }
};
