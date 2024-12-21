class Solution {
 public:
  bool possibleToStamp(vector<vector<int>>& grid, int stampHeight,
                       int stampWidth) {
    const int m = grid.size();
    const int n = grid[0].size();
    // A[i][j] := the number of 1s in grid[0..i)[0..j)
    vector<vector<int>> A(m + 1, vector<int>(n + 1));
    // B[i][j] := the number of ways to stamp the submatrix in [0..i)[0..j)
    vector<vector<int>> B(m + 1, vector<int>(n + 1));
    // fit[i][j] := true if the stamps can fit with the right-bottom at (i, j)
    vector<vector<bool>> fit(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + grid[i][j];
        if (i + 1 >= stampHeight && j + 1 >= stampWidth) {
          const int x = i - stampHeight + 1;
          const int y = j - stampWidth + 1;
          if (A[i + 1][j + 1] - A[x][j + 1] - A[i + 1][y] + A[x][y] == 0)
            fit[i][j] = true;
        }
      }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + fit[i][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!grid[i][j]) {
          const int x = min(i + stampHeight, m);
          const int y = min(j + stampWidth, n);
          if (B[x][y] - B[i][y] - B[x][j] + B[i][j] == 0)
            return false;
        }

    return true;
  }
};
