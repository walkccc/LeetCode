class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); ++i) {
      int maxOfRow = 0;
      int maxOfCol = 0;
      for (int j = 0; j < grid.size(); ++j) {
        maxOfRow = max(maxOfRow, grid[i][j]);
        maxOfCol = max(maxOfCol, grid[j][i]);
        if (grid[i][j])
          ++ans;
      }
      ans += maxOfRow + maxOfCol;
    }

    return ans;
  }
};
