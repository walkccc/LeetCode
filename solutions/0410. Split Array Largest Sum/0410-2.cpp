class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();
    // dp[i][k] := min of largest sum to split first i nums into k groups
    vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
    vector<long> prefix(n + 1);

    partial_sum(begin(nums), end(nums), begin(prefix) + 1);

    for (int i = 1; i <= n; ++i)
      dp[i][1] = prefix[i];

    for (int k = 2; k <= m; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[i][k] = min(dp[i][k], max(dp[j][k - 1], prefix[i] - prefix[j]));

    return dp[n][m];
  }
};
