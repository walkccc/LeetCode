class Solution {
 public:
  vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> ans;
    vector<int> zigzag;

    for (int i = 0; i < m; ++i)
      if (i % 2 == 0) {
        for (int j = 0; j < n; ++j)
          zigzag.push_back(grid[i][j]);
      } else {
        for (int j = n - 1; j >= 0; --j)
          zigzag.push_back(grid[i][j]);
      }

    for (int i = 0; i < zigzag.size(); i += 2)
      ans.push_back(zigzag[i]);

    return ans;
  }
};
