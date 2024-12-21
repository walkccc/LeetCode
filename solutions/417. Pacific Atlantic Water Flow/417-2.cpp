class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    const int m = heights.size();
    const int n = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> seenP(m, vector<bool>(n));
    vector<vector<bool>> seenA(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      dfs(heights, i, 0, seenP);
      dfs(heights, i, n - 1, seenA);
    }

    for (int j = 0; j < n; ++j) {
      dfs(heights, 0, j, seenP);
      dfs(heights, m - 1, j, seenA);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.push_back({i, j});

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& heights, int i, int j,
           vector<vector<bool>>& seen, int h = 0) {
    if (i < 0 || i == heights.size() || j < 0 || j == heights[0].size())
      return;
    if (seen[i][j] || heights[i][j] < h)
      return;

    seen[i][j] = true;
    dfs(heights, i + 1, j, seen, heights[i][j]);
    dfs(heights, i - 1, j, seen, heights[i][j]);
    dfs(heights, i, j + 1, seen, heights[i][j]);
    dfs(heights, i, j - 1, seen, heights[i][j]);
  }
};
