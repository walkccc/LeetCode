class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    // dp[i][j] := max stones you can get more than your opponent in piles[i..j]
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }

    return dp[0][n - 1] > 0;
  }
};
