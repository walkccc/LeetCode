class Solution {
 public:
  int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    int ans = 0;
    // dp[i][j] := the maximum number of queries processed if nums[i..j] are not
    // removed after processing dp[i][j] queries
    vector<vector<int>> dp(n, vector<int>(n));

    for (int d = n - 1; d >= 0; --d) {
      for (int i = 0; i < n; ++i) {
        const int j = i + d;
        if (j >= n)
          continue;
        if (i > 0)
          // Remove nums[i - 1] from nums[i - 1..j] if possible.
          dp[i][j] = max(dp[i][j],
                         dp[i - 1][j] + (nums[i - 1] >= queries[dp[i - 1][j]]));
        if (j + 1 < n)
          // Remove nums[j + 1] from nums[i..j + 1] if possible.
          dp[i][j] = max(dp[i][j],
                         dp[i][j + 1] + (nums[j + 1] >= queries[dp[i][j + 1]]));
        if (dp[i][j] == queries.size())
          return queries.size();
      }
    }

    for (int i = 0; i < n; ++i)
      ans = max(ans, dp[i][i] + (nums[i] >= queries[dp[i][i]]));

    return ans;
  }
};
