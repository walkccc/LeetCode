class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty())
      return;

    const int m = board.size();
    const int n = board[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (board[i][j] == 'O') {
            q.emplace(i, j);
            board[i][j] = '*';
          }

    // Mark the grids that stretch from the four sides with '*'.
    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (board[x][y] != 'O')
          continue;
        q.emplace(x, y);
        board[x][y] = '*';
      }
    }

    for (vector<char>& row : board)
      for (char& c : row)
        if (c == '*')
          c = 'O';
        else if (c == 'O')
          c = 'X';
  }
};
