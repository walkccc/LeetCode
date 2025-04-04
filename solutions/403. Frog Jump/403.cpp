class Solution {
 public:
  bool canCross(vector<int>& stones) {
    const int n = stones.size();
    // dp[i][j] := true if a frog can make a size j jump to stones[i]
    vector<vector<bool>> dp(n, vector<bool>(n + 1));
    dp[0][0] = true;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        const int k = stones[i] - stones[j];
        if (k > n)
          continue;
        for (const int x : {k - 1, k, k + 1})
          if (0 <= x && x <= n)
            dp[i][k] = dp[i][k] || dp[j][x];
      }

    return ranges::any_of(dp.back(), [](bool val) { return val; });
  }
};
