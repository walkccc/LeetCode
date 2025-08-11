class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int ans = 0;

    for (int i = 0; i < grid2.size(); ++i)
      for (int j = 0; j < grid2[0].size(); ++j)
        if (grid2[i][j] == 1)
          ans += dfs(grid1, grid2, i, j);

    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
          int j) {
    if (i < 0 || i == grid1.size() || j < 0 || j == grid2[0].size())
      return 1;
    if (grid2[i][j] != 1)
      return 1;

    grid2[i][j] = 2;  // Mark 2 as visited.

    return dfs(grid1, grid2, i + 1, j) & dfs(grid1, grid2, i - 1, j) &
           dfs(grid1, grid2, i, j + 1) & dfs(grid1, grid2, i, j - 1) &
           grid1[i][j];
  }
};
