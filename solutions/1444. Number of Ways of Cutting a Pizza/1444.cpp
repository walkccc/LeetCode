class Solution {
 public:
  int ways(vector<string>& pizza, int k) {
    const int M = pizza.size();
    const int N = pizza[0].size();
    // dp[m][n][k] := the number of ways to cut pizza[m..M)[n..N) with k cuts
    dp.resize(M, vector<vector<int>>(N, vector<int>(k, -1)));
    prefix.resize(M + 1, vector<int>(N + 1));

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        prefix[i + 1][j + 1] = (pizza[i][j] == 'A') + prefix[i][j + 1] +
                               prefix[i + 1][j] - prefix[i][j];

    return ways(0, 0, k - 1, M, N);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<vector<int>>> dp;
  vector<vector<int>> prefix;

  // Returns true if pizza[row1..row2)[col1..col2) has apple.
  bool hasApple(int row1, int row2, int col1, int col2) {
    return (prefix[row2][col2] - prefix[row1][col2] - prefix[row2][col1] +
            prefix[row1][col1]) > 0;
  };

  int ways(int m, int n, int k, const int M, const int N) {
    if (k == 0)
      return 1;
    if (dp[m][n][k] >= 0)
      return dp[m][n][k];

    dp[m][n][k] = 0;

    for (int i = m + 1; i < M; ++i)  // Cut horizontally.
      if (hasApple(m, i, n, N) && hasApple(i, M, n, N))
        dp[m][n][k] = (dp[m][n][k] + ways(i, n, k - 1, M, N)) % kMod;

    for (int j = n + 1; j < N; ++j)  // Cut vertically.
      if (hasApple(m, M, n, j) && hasApple(m, M, j, N))
        dp[m][n][k] = (dp[m][n][k] + ways(m, j, k - 1, M, N)) % kMod;

    return dp[m][n][k];
  }
};
