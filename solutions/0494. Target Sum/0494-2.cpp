class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum < S || (sum + S) & 1)
      return 0;

    return knapsack(nums, (sum + S) / 2);
  }

 private:
  int knapsack(const vector<int>& nums, int target) {
    // dp[i] := # of ways to sum to i by nums so far
    vector<int> dp(target + 1);
    dp[0] = 1;

    for (const int num : nums)
      for (int i = target; i >= num; --i)
        dp[i] += dp[i - num];

    return dp[target];
  }
};
