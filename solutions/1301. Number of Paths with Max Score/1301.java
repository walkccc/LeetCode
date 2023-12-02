class Solution {
  public int[] pathsWithMaxScore(List<String> board) {
    final int kMod = 1_000_000_007;
    final int n = board.size();
    final int[][] dirs = {{0, 1}, {1, 0}, {1, 1}};
    // dp[i][j] := the maximum sum from (n - 1, n - 1) to (i, j)
    int[][] dp = new int[n + 1][n + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));
    // count[i][j] := the number of paths to get dp[i][j] from (n - 1, n - 1) to (i, j)
    int[][] count = new int[n + 1][n + 1];

    dp[0][0] = 0;
    dp[n - 1][n - 1] = 0;
    count[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        if (board.get(i).charAt(j) == 'S' || board.get(i).charAt(j) == 'X')
          continue;
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (dp[i][j] < dp[x][y]) {
            dp[i][j] = dp[x][y];
            count[i][j] = count[x][y];
          } else if (dp[i][j] == dp[x][y]) {
            count[i][j] += count[x][y];
            count[i][j] %= kMod;
          }
        }
        // If there's path(s) from 'S' to (i, j) and the cell is not 'E'.
        if (dp[i][j] != -1 && board.get(i).charAt(j) != 'E') {
          dp[i][j] += board.get(i).charAt(j) - '0';
          dp[i][j] %= kMod;
        }
      }

    return new int[] {dp[0][0], count[0][0]};
  }
}
