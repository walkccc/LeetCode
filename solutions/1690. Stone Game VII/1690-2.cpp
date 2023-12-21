class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    const int n = stones.size();
    // dp[i][j] := the maximum score you can get more than your opponent in
    // stones[i..j]
    vector<vector<int>> dp(n, vector<int>(n));
    vector<int> prefix(n + 1);

    partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        dp[i][j] = max(prefix[j + 1] - prefix[i + 1] - dp[i + 1][j],
                       prefix[j] - prefix[i] - dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
};
