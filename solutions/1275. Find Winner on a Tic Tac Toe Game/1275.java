class Solution {
  public String tictactoe(int[][] moves) {
    int[][] row = new int[2][3];
    int[][] col = new int[2][3];
    int[] diag1 = new int[2];
    int[] diag2 = new int[2];

    for (int i = 0; i < moves.length; ++i) {
      int r = moves[i][0];
      int c = moves[i][1];
      int j = i % 2;
      if (++row[j][r] == 3 || ++col[j][c] == 3 || r == c && ++diag1[j] == 3 ||
          r + c == 2 && ++diag2[j] == 3)
        return j == 0 ? "A" : "B";
    }

    return moves.length == 9 ? "Draw" : "Pending";
  }
}
