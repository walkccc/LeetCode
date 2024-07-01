class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<int>>> mem(m,
                                    vector<vector<int>>(n, vector<int>(n, -1)));
    return cherryPick(grid, 0, 0, n - 1, mem);
  }

 private:
  // Returns the maximum cherries we can collect, where the robot #1 is on
  // (x, y1) and the robot #2 is on (x, y2).
  int cherryPick(const vector<vector<int>>& grid, int x, int y1, int y2,
                 vector<vector<vector<int>>>& mem) {
    if (x == grid.size())
      return 0;
    if (y1 < 0 || y1 == grid[0].size() || y2 < 0 || y2 == grid[0].size())
      return 0;
    if (mem[x][y1][y2] != -1)
      return mem[x][y1][y2];

    const int currRow = grid[x][y1] + (y1 == y2 ? 0 : 1) * grid[x][y2];

    for (int d1 = -1; d1 <= 1; ++d1)
      for (int d2 = -1; d2 <= 1; ++d2)
        mem[x][y1][y2] =
            max(mem[x][y1][y2],
                currRow + cherryPick(grid, x + 1, y1 + d1, y2 + d2, mem));

    return mem[x][y1][y2];
  }
};
