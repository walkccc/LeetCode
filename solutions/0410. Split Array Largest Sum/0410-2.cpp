class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    const int n = nums.size();
    // dp[i][k] := the minimum of the maximum sum to split the first i nums into
    // k groups
    vector<vector<long>> dp(n + 1, vector<long>(k + 1, INT_MAX));
    vector<long> prefix(n + 1);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    for (int i = 1; i <= n; ++i)
      dp[i][1] = prefix[i];

    for (int l = 2; l <= k; ++l)
      for (int i = l; i <= n; ++i)
        for (int j = l - 1; j < i; ++j)
          dp[i][l] = min(dp[i][l], max(dp[j][l - 1], prefix[i] - prefix[j]));

    return dp[n][k];
  }
};
