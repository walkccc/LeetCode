class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    const int i = click[0];
    const int j = click[1];
    if (board[i][j] == 'M') {
      board[i][j] = 'X';
      return board;
    }

    dfs(board, i, j);
    return board;
  }

 private:
  static constexpr int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
      return;
    if (board[i][j] != 'E')
      return;

    const int minesCount = getMinesCount(board, i, j);
    board[i][j] = minesCount == 0 ? 'B' : '0' + minesCount;

    if (minesCount == 0)
      for (const auto& [dx, dy] : dirs)
        dfs(board, i + dx, j + dy);
  }

  int getMinesCount(const vector<vector<char>>& board, int i, int j) {
    int minesCount = 0;
    for (const auto& [dx, dy] : dirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x == board.size() || y < 0 || y == board[0].size())
        continue;
      if (board[x][y] == 'M')
        ++minesCount;
    }
    return minesCount;
  }
};
