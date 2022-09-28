class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    this->m = m;
    this->n = n;
    // dp[k][i][j] := # of paths to move the ball (i, j) out of bound w/ k moves
    dp.resize(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
    return findPaths(maxMove, startRow, startColumn);
  }

 private:
  constexpr static int kMod = 1'000'000'007;
  int m;
  int n;
  vector<vector<vector<int>>> dp;

  int findPaths(int k, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (dp[k][i][j] != -1)
      return dp[k][i][j];
    return dp[k][i][j] =
      ((findPaths(k - 1, i + 1, j) + findPaths(k - 1, i - 1, j)) % kMod +
       (findPaths(k - 1, i, j + 1) + findPaths(k - 1, i, j - 1)) % kMod) %
        kMod;
  }
};
