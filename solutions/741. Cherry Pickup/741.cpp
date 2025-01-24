class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    // The problem is identical as two people start picking cherries from
    // grid[0][0] simultaneously.
    const int n = grid.size();
    vector<vector<vector<int>>> mem(
        n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));
    return max(0, cherryPickup(grid, 0, 0, 0, mem));
  }

 private:
  // Returns the maximum cherries we could pick from g[0][0] ->
  // g[x1 - 1][y1 - 1] + g[0][0] -> g[x2 - 1][y2 - 1], where y2 = x1 + y1 - x2
  // (reducing states from 4 to 3).
  int cherryPickup(const vector<vector<int>>& grid, int x1, int y1, int x2,
                   vector<vector<vector<int>>>& mem) {
    const int n = grid.size();
    const int y2 = x1 + y1 - x2;
    if (x1 == n || y1 == n || x2 == n || y2 == n)
      return -1;
    if (x1 == n - 1 && y1 == n - 1)
      return grid[x1][y1];
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
      return -1;
    int& res = mem[x1][y1][x2];
    if (mem[x1][y1][x2] > INT_MIN)
      return res;

    res = max({cherryPickup(grid, x1 + 1, y1, x2, mem),
               cherryPickup(grid, x1 + 1, y1, x2 + 1, mem),
               cherryPickup(grid, x1, y1 + 1, x2, mem),
               cherryPickup(grid, x1, y1 + 1, x2 + 1, mem)});
    if (res == -1)
      return res;

    res += grid[x1][y1];  // Pick some cherries.
    if (x1 != x2)         // Two people are on the different grids.
      res += grid[x2][y2];

    return res;
  }
};
