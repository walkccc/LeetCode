class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned long> dp(target + 1);
    dp[0] = 1;

    for (int i = 1; i <= target; ++i)
      for (const int num : nums)
        if (i >= num)
          dp[i] += dp[i - num];

    return dp[target];
  }
};
