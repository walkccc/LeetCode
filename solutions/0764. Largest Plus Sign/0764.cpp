class Solution {
 public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int>> grid(N, vector<int>(N, N));

    for (const auto& mine : mines)
      grid[mine[0]][mine[1]] = 0;

    // extend four directions, if meet 0, need to start over from 0
    for (int i = 0; i < N; ++i) {
      for (int j = 0, leftToRight = 0; j < N; ++j) {
        leftToRight = (grid[i][j] == 0 ? 0 : leftToRight + 1);
        grid[i][j] = min(grid[i][j], leftToRight);
      }
      for (int j = N - 1, rightToLeft = 0; j >= 0; --j) {
        rightToLeft = (grid[i][j] == 0 ? 0 : rightToLeft + 1);
        grid[i][j] = min(grid[i][j], rightToLeft);
      }
      for (int j = 0, upToDown = 0; j < N; ++j) {
        upToDown = (grid[j][i] == 0 ? 0 : upToDown + 1);
        grid[j][i] = min(grid[j][i], upToDown);
      }
      for (int j = N - 1, downToUp = 0; j >= 0; --j) {
        downToUp = (grid[j][i] == 0) ? 0 : downToUp + 1;
        grid[j][i] = min(grid[j][i], downToUp);
      }
    }

    int ans = 0;

    for (const auto& row : grid)
      ans = max(ans, *max_element(begin(row), end(row)));

    return ans;
  }
};
