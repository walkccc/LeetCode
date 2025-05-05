class Solution {
 public:
  long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
    const int n = nums.size();
    vector<long> prefixNums(n + 1);
    vector<long> prefixCost(n + 1);
    // dp[i] := the minimum cost to divide nums[i..n - 1] into subarrays
    vector<long> dp(n + 1, LONG_MAX);

    partial_sum(nums.begin(), nums.end(), prefixNums.begin() + 1);
    partial_sum(cost.begin(), cost.end(), prefixCost.begin() + 1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        dp[i] =
            min(dp[i], prefixNums[j + 1] * (prefixCost[j + 1] - prefixCost[i]) +
                           k * (prefixCost[n] - prefixCost[i]) + dp[j + 1]);

    return dp[0];
  }
};
