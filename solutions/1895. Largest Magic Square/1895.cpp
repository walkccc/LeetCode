class Solution {
 public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // prefixRow[i][j] := the sum of the first j numbers in the i-th row
    vector<vector<int>> prefixRow(m, vector<int>(n + 1));
    // prefixCol[i][j] := the sum of the first j numbers in the i-th column
    vector<vector<int>> prefixCol(n, vector<int>(m + 1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        prefixRow[i][j + 1] = prefixRow[i][j] + grid[i][j];
        prefixCol[j][i + 1] = prefixCol[j][i] + grid[i][j];
      }

    for (int k = min(m, n); k >= 2; --k)
      if (containsMagicSquare(grid, prefixRow, prefixCol, k))
        return k;

    return 1;
  }

 private:
  // Returns true if the grid contains any magic square of size k x k.
  bool containsMagicSquare(const vector<vector<int>>& grid,
                           const vector<vector<int>>& prefixRow,
                           const vector<vector<int>>& prefixCol, int k) {
    for (int i = 0; i + k - 1 < grid.size(); ++i)
      for (int j = 0; j + k - 1 < grid[0].size(); ++j)
        if (isMagicSquare(grid, prefixRow, prefixCol, i, j, k))
          return true;
    return false;
  }

  // Returns true if grid[i..i + k)[j..j + k) is a magic square.
  bool isMagicSquare(const vector<vector<int>>& grid,
                     const vector<vector<int>>& prefixRow,
                     const vector<vector<int>>& prefixCol, int i, int j,
                     int k) {
    int diag = 0;
    int antiDiag = 0;
    for (int d = 0; d < k; ++d) {
      diag += grid[i + d][j + d];
      antiDiag += grid[i + d][j + k - 1 - d];
    }
    if (diag != antiDiag)
      return false;
    for (int d = 0; d < k; ++d) {
      if (getSum(prefixRow, i + d, j, j + k - 1) != diag)
        return false;
      if (getSum(prefixCol, j + d, i, i + k - 1) != diag)
        return false;
    }
    return true;
  }

  // Returns sum(grid[i][l..r]) or sum(grid[l..r][i]).
  int getSum(const vector<vector<int>>& prefix, int i, int l, int r) {
    return prefix[i][r + 1] - prefix[i][l];
  }
};
