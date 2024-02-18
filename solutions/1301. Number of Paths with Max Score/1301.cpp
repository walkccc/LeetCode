class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    constexpr int kMod = 1'000'000'007;
    const int n = board.size();
    const vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {1, 1}};
    // dp[i][j] := the maximum sum from (n - 1, n - 1) to (i, j)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // count[i][j] := the number of paths to get dp[i][j] from (n - 1, n - 1) to
    // (i, j)
    vector<vector<int>> count(n + 1, vector<int>(n + 1));

    dp[0][0] = 0;
    dp[n - 1][n - 1] = 0;
    count[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] == 'S' || board[i][j] == 'X')
          continue;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (dp[i][j] < dp[x][y]) {
            dp[i][j] = dp[x][y];
            count[i][j] = count[x][y];
          } else if (dp[i][j] == dp[x][y]) {
            count[i][j] += count[x][y];
            count[i][j] %= kMod;
          }
        }
        // If there's path(s) from 'S' to (i, j) and the cell is not 'E'.
        if (dp[i][j] != -1 && board[i][j] != 'E') {
          dp[i][j] += board[i][j] - '0';
          dp[i][j] %= kMod;
        }
      }

    return {dp[0][0], count[0][0]};
  }
};
