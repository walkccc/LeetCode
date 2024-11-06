class Solution {
 public:
  int waysToReachTarget(int target, vector<vector<int>>& types) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][j] := the number of ways to earn j points with the first i types
    vector<vector<int>> dp(types.size() + 1, vector<int>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= types.size(); ++i) {
      const int count = types[i - 1][0];
      const int mark = types[i - 1][1];
      for (int j = 0; j <= target; ++j)
        for (int solved = 0; solved <= count; ++solved)
          if (j - solved * mark >= 0) {
            dp[i][j] += dp[i - 1][j - solved * mark];
            dp[i][j] %= kMod;
          }
    }

    return dp[types.size()][target];
  }
};
