class Solution {
 public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove,
                 char color) {
    const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    for (const auto& [dx, dy] : dirs) {
      int cellsCount = 2;
      int i = rMove + dx;
      int j = cMove + dy;
      while (0 <= i && i < 8 && 0 <= j && j < 8) {
        // There are no free cells in between.
        if (board[i][j] == '.')
          break;
        // Need >= 3 cells.
        if (cellsCount == 2 && board[i][j] == color)
          break;
        // >= 3 cells.
        if (board[i][j] == color)
          return true;
        i += dx;
        j += dy;
        ++cellsCount;
      }
    }

    return false;
  }
};
