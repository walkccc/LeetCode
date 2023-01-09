class Solution {
 public:
  int mergeStones(vector<int>& stones, int K) {
    const int n = stones.size();
    if ((n - 1) % (K - 1))
      return -1;

    constexpr int kMax = 1'000'000'000;

    // dp[i][j] := min cost to merge stones[i..j]
    vector<vector<int>> dp(n, vector<int>(n, kMax));
    vector<int> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      dp[i][i] = 0;

    partial_sum(begin(stones), end(stones), begin(prefix) + 1);

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        for (int m = i; m < j; m += K - 1)
          dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
        if (d % (K - 1) == 0)
          dp[i][j] += prefix[j + 1] - prefix[i];
      }

    return dp[0][n - 1];
  }
};
