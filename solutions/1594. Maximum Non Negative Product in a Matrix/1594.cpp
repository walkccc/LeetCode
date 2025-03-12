class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    constexpr int kMod = 1'000'000'007;
    const int m = grid.size();
    const int n = grid[0].size();
    // dpMin[i][j] := the minimum product from (0, 0) to (i, j)
    // dpMax[i][j] := the maximum product from (0, 0) to (i, j)
    vector<vector<long>> dpMin(m, vector<long>(n));
    vector<vector<long>> dpMax(m, vector<long>(n));

    dpMin[0][0] = dpMax[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i)
      dpMin[i][0] = dpMax[i][0] = dpMin[i - 1][0] * grid[i][0];

    for (int j = 1; j < n; ++j)
      dpMin[0][j] = dpMax[0][j] = dpMin[0][j - 1] * grid[0][j];

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (grid[i][j] < 0) {
          dpMin[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
          dpMax[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
        } else {
          dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
          dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
        }

    const long mx = max(dpMin.back().back(), dpMax.back().back());
    return mx < 0 ? -1 : mx % kMod;
  }
};
