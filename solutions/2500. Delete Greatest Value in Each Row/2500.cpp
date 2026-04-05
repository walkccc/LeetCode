class Solution {
 public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    int ans = 0;

    for (vector<int>& row : grid)
      ranges::sort(row);

    for (int j = 0; j < grid[0].size(); ++j) {
      int maxOfColumn = 0;
      for (int i = 0; i < grid.size(); ++i)
        maxOfColumn = max(maxOfColumn, grid[i][j]);
      ans += maxOfColumn;
    }

    return ans;
  }
};
