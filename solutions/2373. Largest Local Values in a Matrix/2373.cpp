class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    const int n = grid.size();
    vector<vector<int>> ans(n - 2, vector<int>(n - 2));

    for (int i = 0; i < n - 2; ++i)
      for (int j = 0; j < n - 2; ++j)
        for (int x = i; x < i + 3; ++x)
          for (int y = j; y < j + 3; ++y)
            ans[i][j] = max(ans[i][j], grid[x][y]);

    return ans;
  }
};
