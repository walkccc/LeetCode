class Solution {
 public:
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      fillInDiagonal(grid, i, 0, ans);

    for (int j = 1; j < n; ++j)
      fillInDiagonal(grid, 0, j, ans);

    return ans;
  }

 private:
  void fillInDiagonal(const vector<vector<int>>& grid, int i, int j,
                      vector<vector<int>>& ans) {
    unordered_set<int> topLeft;
    unordered_set<int> bottomRight;

    // Fill in the diagonal from the top-left to the bottom-right.
    while (i < grid.size() && j < grid[0].size()) {
      ans[i][j] = topLeft.size();
      // Post-addition, so this information can be utilized in subsequent cells.
      topLeft.insert(grid[i++][j++]);
    }

    --i;
    --j;

    // Fill in the diagonal from the bottom-right to the top-left.
    while (i >= 0 && j >= 0) {
      ans[i][j] = abs(ans[i][j] - static_cast<int>(bottomRight.size()));
      // Post-addition, so this information can be utilized in subsequent cells.
      bottomRight.insert(grid[i--][j--]);
    }
  }
};
