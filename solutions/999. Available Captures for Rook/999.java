class Solution {
  public int numRookCaptures(char[][] board) {
    int ans = 0;
    int i0 = 0;
    int j0 = 0;

    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (board[i][j] == 'R') {
          i0 = i;
          j0 = j;
        }

    for (int[] d : new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}})
      for (int i = i0 + d[0], j = j0 + d[1]; 0 <= i && i < 8 && 0 <= j && j < 8;
           i += d[0], j += d[1]) {
        if (board[i][j] == 'p')
          ++ans;
        if (board[i][j] != '.')
          break;
      }

    return ans;
  }
}
