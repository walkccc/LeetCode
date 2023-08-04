class Solution {
 public:
  vector<int> findColumnWidth(vector<vector<int>>& grid) {
    vector<int> ans;

    for (int j = 0; j < grid[0].size(); ++j) {
      ans.push_back(0);
      for (int i = 0; i < grid.size(); ++i)
        ans[j] = max(ans[j], static_cast<int>(to_string(grid[i][j]).length()));
    }

    return ans;
  }
};
