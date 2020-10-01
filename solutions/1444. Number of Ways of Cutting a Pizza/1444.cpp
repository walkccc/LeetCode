class Solution {
 public:
  int ways(vector<string>& pizza, int k) {
    constexpr int kMod = 1e9 + 7;
    const int M = pizza.size();
    const int N = pizza[0].size();

    vector<vector<vector<int>>> memo(M, vector<vector<int>>(N, vector<int>(k, -1)));
    vector<vector<int>> prefixSum(M + 1, vector<int>(N + 1));

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] +
                                  (pizza[i][j] == 'A') - prefixSum[i][j];

    // hasApple of pizza[row1:row2)[col1:col2)
    auto hasApple = [&prefixSum](int row1, int row2, int col1, int col2) {
      return (prefixSum[row2][col2] - prefixSum[row1][col2] -
              prefixSum[row2][col1] + prefixSum[row1][col1]) > 0;
    };

    // dp(m, n, k) := # of ways to cut pizza[m:M)[n:N) with k cuts
    function<int(int, int, int)> dp = [&](int m, int n, int k) -> int {
      if (k == 0) return 1;
      int& ans = memo[m][n][k];
      if (ans >= 0) return ans;

      ans = 0;

      for (int i = m + 1; i < M; ++i)  // cut horizontally
        if (hasApple(m, i, n, N) && hasApple(i, M, n, N))
          ans = (ans + dp(i, n, k - 1)) % kMod;

      for (int j = n + 1; j < N; ++j)  // cut vertically
        if (hasApple(m, M, n, j) && hasApple(m, M, j, N))
          ans = (ans + dp(m, j, k - 1)) % kMod;

      return ans;
    };

    return dp(0, 0, k - 1);
  }
};