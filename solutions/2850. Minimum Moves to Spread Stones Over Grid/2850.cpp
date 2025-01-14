class Solution {
 public:
  int minimumMoves(vector<vector<int>>& grid) {
    const int zeroCount = accumulate(grid.begin(), grid.end(), 0,
                                     [](int subtotal, const vector<int>& row) {
      return subtotal + ranges::count(row, 0);
    });
    if (zeroCount == 0)
      return 0;

    int ans = INT_MAX;

    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (grid[i][j] == 0)
          for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
              // Move a stone at (x, y) to (i, j).
              if (grid[x][y] > 1) {
                --grid[x][y];
                ++grid[i][j];
                ans = min(ans, abs(x - i) + abs(y - j) + minimumMoves(grid));
                ++grid[x][y];
                --grid[i][j];
              }

    return ans;
  }
};
