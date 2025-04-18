class Solution {
 public:
  int sumOfPower(vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    // dp[i] := the number of subsequences in nums so far that sums to k
    vector<int> dp(k + 1);
    dp[0] = 1;

    for (const int num : nums)
      for (int i = k; i >= 0; --i)
        if (i < num)
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          dp[i] = (dp[i] * 2L) % kMod;
        else
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          // 3. Include nums[i] in the subsequence and pick it.
          dp[i] = (dp[i] * 2L + dp[i - num]) % kMod;

    return dp[k];
  }
};
