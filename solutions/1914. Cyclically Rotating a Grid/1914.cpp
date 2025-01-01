class Solution {
 public:
  vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    int t = 0;      // the top
    int l = 0;      // the left
    int b = m - 1;  // the bottom
    int r = n - 1;  // the right

    while (t < b && l < r) {
      const int elementInThisLayer = 2 * (b - t + 1) + 2 * (r - l + 1) - 4;
      const int netRotations = k % elementInThisLayer;
      for (int rotate = 0; rotate < netRotations; ++rotate) {
        const int topLeft = grid[t][l];
        for (int j = l; j < r; ++j)
          grid[t][j] = grid[t][j + 1];
        for (int i = t; i < b; ++i)
          grid[i][r] = grid[i + 1][r];
        for (int j = r; j > l; --j)
          grid[b][j] = grid[b][j - 1];
        for (int i = b; i > t; --i)
          grid[i][l] = grid[i - 1][l];
        grid[t + 1][l] = topLeft;
      }
      ++t;
      ++l;
      --b;
      --r;
    }

    return grid;
  }
};
