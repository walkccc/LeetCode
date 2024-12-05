class Solution {
 public:
  int ways(vector<string>& pizza, int k) {
    const int M = pizza.size();
    const int N = pizza[0].size();
    vector<vector<vector<int>>> mem(M,
                                    vector<vector<int>>(N, vector<int>(k, -1)));
    vector<vector<int>> prefix(M + 1, vector<int>(N + 1));

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        prefix[i + 1][j + 1] = (pizza[i][j] == 'A') + prefix[i][j + 1] +
                               prefix[i + 1][j] - prefix[i][j];

    return ways(0, 0, k - 1, M, N, prefix, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of ways to cut pizza[m..M)[n..N) with k cuts.
  int ways(int m, int n, int k, const int M, const int N,
           const vector<vector<int>>& prefix,
           vector<vector<vector<int>>>& mem) {
    if (k == 0)
      return hasApple(prefix, m, M, n, N) ? 1 : 0;
    if (mem[m][n][k] != -1)
      return mem[m][n][k];

    mem[m][n][k] = 0;

    for (int i = m + 1; i < M; ++i)  // Cut horizontally.
      if (hasApple(prefix, m, i, n, N) && hasApple(prefix, i, M, n, N)) {
        mem[m][n][k] += ways(i, n, k - 1, M, N, prefix, mem);
        mem[m][n][k] %= kMod;
      }

    for (int j = n + 1; j < N; ++j)  // Cut vertically.
      if (hasApple(prefix, m, M, n, j) && hasApple(prefix, m, M, j, N)) {
        mem[m][n][k] += ways(m, j, k - 1, M, N, prefix, mem);
        mem[m][n][k] %= kMod;
      }

    return mem[m][n][k];
  }

  // Returns true if pizza[row1..row2)[col1..col2) has apple.
  bool hasApple(const vector<vector<int>>& prefix, int row1, int row2, int col1,
                int col2) {
    return (prefix[row2][col2] - prefix[row1][col2] -  //
            prefix[row2][col1] + prefix[row1][col1]) > 0;
  };
};
