class Solution {
 public:
  int validSubarraySplit(vector<int>& nums) {
    constexpr int kMax = INT_MAX / 2;
    // dp[i] := the minimum number of subarrays to validly split nums[0..i]
    vector<int> dp(nums.size(), kMax);

    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j <= i; ++j)
        if (__gcd(nums[j], nums[i]) > 1)
          dp[i] = min(dp[i], j == 0 ? 1 : dp[j - 1] + 1);

    return dp.back() == kMax ? -1 : dp.back();
  }
};
