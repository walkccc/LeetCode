class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    const int m = board.size();
    const int n = board[0].size();
    const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    auto getMinesCount = [&](int i, int j) {
      int minesCount = 0;
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n) continue;
        if (board[x][y] == 'M') ++minesCount;
      }
      return minesCount;
    };

    function<void(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (board[i][j] != 'E') return;

      const int minesCount = getMinesCount(i, j);
      board[i][j] = minesCount == 0 ? 'B' : '0' + minesCount;

      if (minesCount == 0)
        for (const auto& [dx, dy] : dirs)
          dfs(i + dx, j + dy);
    };

    dfs(click[0], click[1]);

    return board;
  }
};