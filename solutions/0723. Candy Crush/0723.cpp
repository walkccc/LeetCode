class Solution {
 public:
  vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    const int m = board.size();
    const int n = board[0].size();
    bool haveCrushes = true;

    while (haveCrushes) {
      haveCrushes = false;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          const int val = abs(board[i][j]);
          if (val == 0)
            continue;
          // crush vertical candies
          if (j + 2 < n && abs(board[i][j + 1]) == val &&
              abs(board[i][j + 2]) == val) {
            haveCrushes = true;
            for (int k = j; k < j + 3; ++k)
              board[i][k] = -val;
          }
          // crush horizontal candies
          if (i + 2 < m && abs(board[i + 1][j]) == val &&
              abs(board[i + 2][j]) == val) {
            haveCrushes = true;
            for (int k = i; k < i + 3; ++k)
              board[k][j] = -val;
          }
        }

      if (haveCrushes) {
        // for each column, drop candies
        for (int j = 0; j < n; ++j) {
          int nextIndex = m - 1;
          for (int i = m - 1; i >= 0; --i)
            if (board[i][j] > 0)
              board[nextIndex--][j] = board[i][j];
          // set board[0..nextIndex][j] to 0s
          for (int i = nextIndex; i >= 0; --i)
            board[i][j] = 0;
        }
      }
    }

    return board;
  }
};
