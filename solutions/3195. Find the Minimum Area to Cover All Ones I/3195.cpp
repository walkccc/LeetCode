class Solution {
 public:
  int minimumArea(vector<vector<int>>& grid) {
    int x1 = INT_MAX;
    int y1 = INT_MAX;
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          x1 = min(x1, i);
          y1 = min(y1, j);
          x2 = max(x2, i);
          y2 = max(y2, j);
        }

    return (x2 - x1 + 1) * (y2 - y1 + 1);
  }
};
