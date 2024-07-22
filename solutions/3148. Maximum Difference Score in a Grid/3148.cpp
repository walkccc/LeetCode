class Solution {
 public:
  int maxScore(vector<vector<int>>& grid) {
    constexpr int kMax = 200'000;
    int ans = -kMax;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j) {
        const int prevMin = min(i > 0 ? grid[i - 1][j] : kMax,  //
                                j > 0 ? grid[i][j - 1] : kMax);
        ans = max(ans, grid[i][j] - prevMin);
        grid[i][j] = min(grid[i][j], prevMin);
      }

    return ans;
  }
};
