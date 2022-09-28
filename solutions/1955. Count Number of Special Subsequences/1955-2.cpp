class Solution {
 public:
  int countSpecialSubsequences(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    // dp[i][j] := # of increasing subseqs of nums[:i] ending at j
    vector<vector<long>> dp(n, vector<long>(3));

    if (nums[0] == 0)
      dp[0][0] = 1;

    for (int i = 1; i < n; ++i) {
      for (int endingAt = 0; endingAt < 3; ++endingAt)
        dp[i][endingAt] = dp[i - 1][endingAt];

      if (nums[i] == 0)
        // prev ending at 0 + prev ending at 0 + [0] + start new from this 0
        dp[i][0] = dp[i - 1][0] * 2 + 1;
      else if (nums[i] == 1)
        // prev ending at 1 + prev ending at 1 + [1] + prev ending at 0 + [1]
        dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0];
      else  // nums[i] == 2
        // prev ending at 2 + prev ending at 2 + [2] + prev ending at 1 + [2]
        dp[i][2] = dp[i - 1][2] * 2 + dp[i - 1][1];

      for (int endingAt = 0; endingAt < 3; ++endingAt)
        dp[i][endingAt] %= kMod;
    }

    return dp.back()[2];
  }
};
