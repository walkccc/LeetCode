class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<int>> grid(n, vector<int>(n, n));

    for (const vector<int>& mine : mines)
      grid[mine[0]][mine[1]] = 0;

    // Extend the four directions. If meet 0, need to start over from 0.
    for (int i = 0; i < n; ++i) {
      for (int j = 0, leftToRight = 0; j < n; ++j) {
        leftToRight = (grid[i][j] == 0 ? 0 : leftToRight + 1);
        grid[i][j] = min(grid[i][j], leftToRight);
      }
      for (int j = n - 1, rightToLeft = 0; j >= 0; --j) {
        rightToLeft = (grid[i][j] == 0 ? 0 : rightToLeft + 1);
        grid[i][j] = min(grid[i][j], rightToLeft);
      }
      for (int j = 0, upToDown = 0; j < n; ++j) {
        upToDown = (grid[j][i] == 0 ? 0 : upToDown + 1);
        grid[j][i] = min(grid[j][i], upToDown);
      }
      for (int j = n - 1, downToUp = 0; j >= 0; --j) {
        downToUp = (grid[j][i] == 0) ? 0 : downToUp + 1;
        grid[j][i] = min(grid[j][i], downToUp);
      }
    }

    int ans = 0;

    for (const vector<int>& row : grid)
      ans = max(ans, ranges::max(row));

    return ans;
  }
};
