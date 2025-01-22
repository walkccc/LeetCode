class Solution {
 public:
  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    const int n = nums.size();
    // dp[i][j] := the maximum length of any subsequence of the first i numbers
    // that sum to j
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
      const int num = nums[i - 1];
      for (int j = 1; j <= target; ++j)
        // 1. Skip `num`.
        if (j < num || dp[i - 1][j - num] == -1)
          dp[i][j] = dp[i - 1][j];
        // 2. Skip `num` or pick `num`.
        else
          dp[i][j] = max(dp[i - 1][j], 1 + dp[i - 1][j - num]);
    }

    return dp[n][target];
  }
};
