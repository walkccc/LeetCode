class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    auto isNeighborRotten = [&](int i, int j, const vector<vector<int>>& grid) {
      for (int k = 0; k < 4; ++k) {
        const int r = i + dirs[k];
        const int c = j + dirs[k + 1];
        if (r < 0 || r == m || c < 0 || c == n)
          continue;
        if (grid[r][c] == 2)
          return true;
      }
      return false;
    };

    int ans = 0;

    while (true) {
      vector<vector<int>> nextGrid(m, vector<int>(n));
      // Calculate the `nextGrid` based on the `grid`.
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1) {  // fresh
            // Any of the 4-directionally oranges is rotten
            if (isNeighborRotten(i, j, grid))
              nextGrid[i][j] = 2;
            else
              nextGrid[i][j] = 1;
          } else if (grid[i][j] == 2) {  // rotten
            nextGrid[i][j] = 2;          // Keep rotten.
          }
      if (nextGrid == grid)
        break;
      grid = nextGrid;
      ++ans;
    }

    return any_of(grid.begin(), grid.end(),
                  [&](vector<int>& row) {
      return ranges::any_of(row, [&](int orange) { return orange == 1; });
    })
               ? -1
               : ans;
  }
};
