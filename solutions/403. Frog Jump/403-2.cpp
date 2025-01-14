class Solution {
 public:
  bool canCross(vector<int>& stones) {
    const int n = stones.size();
    // dp[i][j] := true if a frog can make a size j jump from stones[i]
    vector<vector<bool>> dp(n, vector<bool>(n + 1));
    dp[0][1] = true;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        const int k = stones[i] - stones[j];
        if (k <= n && dp[j][k]) {
          dp[i][k - 1] = true;
          dp[i][k] = true;
          dp[i][k + 1] = true;
        }
      }

    return ranges::any_of(dp.back(), [](bool val) { return val; });
  }
};
