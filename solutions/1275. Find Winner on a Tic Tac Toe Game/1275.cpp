class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<int>> row(2, vector<int>(3));
    vector<vector<int>> col(2, vector<int>(3));
    vector<int> diag1(2);
    vector<int> diag2(2);

    for (int i = 0; i < moves.size(); ++i) {
      const int r = moves[i][0];
      const int c = moves[i][1];
      const int j = i & 1;
      if (++row[j][r] == 3 || ++col[j][c] == 3 || r == c && ++diag1[j] == 3 ||
          r + c == 2 && ++diag2[j] == 3)
        return j == 0 ? "A" : "B";
    }

    return moves.size() == 9 ? "Draw" : "Pending";
  }
};
