class Solution {
 public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int ans = 0;

    for (int row1 = 0; row1 < grid.size() - 1; ++row1)
      for (int row2 = row1 + 1; row2 < grid.size(); ++row2) {
        int count = 0;
        for (int j = 0; j < grid[0].size(); ++j)
          if (grid[row1][j] && grid[row2][j])
            ++count;
        ans += count * (count - 1) / 2;
      }

    return ans;
  }
};
