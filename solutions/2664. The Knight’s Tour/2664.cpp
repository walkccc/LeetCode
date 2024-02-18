class Solution {
 public:
  vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
    vector<vector<int>> ans(m, vector<int>(n, -1));
    dfs(m, n, r, c, 0, ans);
    return ans;
  }

 private:
  static constexpr int dirs[8][2] = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                     {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

  bool dfs(int m, int n, int i, int j, int step, vector<vector<int>>& ans) {
    if (step == m * n)
      return true;
    if (i < 0 || i >= m || j < 0 || j >= n)
      return false;
    if (ans[i][j] != -1)
      return false;
    ans[i][j] = step;
    for (const auto& [dx, dy] : dirs)
      if (dfs(m, n, i + dx, j + dy, step + 1, ans))
        return true;
    ans[i][j] = -1;
    return false;
  }
};
