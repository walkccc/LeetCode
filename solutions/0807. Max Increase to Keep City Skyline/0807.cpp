class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    const int n = grid.size();
    int ans = 0;
    vector<int> rowMax(n);
    vector<int> colMax(n);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        rowMax[i] = max(rowMax[i], grid[i][j]);
        colMax[j] = max(colMax[j], grid[i][j]);
      }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ans += min(rowMax[i], colMax[j]) - grid[i][j];

    return ans;
  }
};
