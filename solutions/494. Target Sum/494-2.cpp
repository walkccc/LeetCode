class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 == 1)
      return 0;
    return knapsack(nums, (sum + target) / 2);
  }

 private:
  int knapsack(const vector<int>& nums, int target) {
    // dp[i] := the number of ways to sum to i by nums so far
    vector<int> dp(target + 1);
    dp[0] = 1;

    for (const int num : nums)
      for (int i = target; i >= num; --i)
        dp[i] += dp[i - num];

    return dp[target];
  }
};
