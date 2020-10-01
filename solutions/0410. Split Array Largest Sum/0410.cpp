class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();

    // dp[i][k] := min of largest sum to split first i nums into k groups
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
    vector<long> prefixSum(n + 1);  // prefixSum[i] := sum of first i nums

    for (int i = 1; i <= n; ++i) {
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
      dp[i][1] = prefixSum[i];
    }

    for (int k = 2; k <= m; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[i][k] = min(dp[i][k], max(dp[j][k - 1], prefixSum[i] - prefixSum[j]));

    return dp[n][m];
  }
};