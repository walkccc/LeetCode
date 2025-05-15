class Solution {
 public:
  bool checkValidGrid(vector<vector<int>>& grid) {
    if (grid[0][0] != 0)
      return false;

    const int n = grid.size();
    int i = 0;
    int j = 0;

    for (int target = 1; target < n * n; ++target) {
      const auto [x, y] = nextGrid(grid, i, j, target);
      if (x == -1 && y == -1)
        return false;
      // Move (x, y) to (i, j).
      i = x;
      j = y;
    }

    return true;
  }

 private:
  static constexpr int kDirs[8][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                      {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  // Returns (x, y), where grid[x][y] == target if (i, j) can reach target.
  pair<int, int> nextGrid(const vector<vector<int>>& grid, int i, int j,
                          int target) {
    const int n = grid.size();
    for (const auto& [dx, dy] : kDirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x >= n || y < 0 || y >= n)
        continue;
      if (grid[x][y] == target)
        return {x, y};
    }
    return {-1, -1};
  }
};
