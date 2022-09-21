class Solution {
 public:
  int mergeStones(vector<int>& stones, int K) {
    const int n = stones.size();
    if ((n - 1) % (K - 1))
      return -1;

    constexpr int kMax = 1'000'000'000;

    // dp[i][j][k] := min cost to merge stones[i..j] into k piles
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(K + 1, kMax)));
    vector<int> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      dp[i][i][1] = 0;

    partial_sum(begin(stones), end(stones), begin(prefix) + 1);

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        for (int k = 2; k <= K; ++k)  // piles
          for (int m = i; m < j; m += K - 1)
            dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
        dp[i][j][1] = dp[i][j][K] + prefix[j + 1] - prefix[i];
      }

    return dp[0][n - 1][1];
  }
};
