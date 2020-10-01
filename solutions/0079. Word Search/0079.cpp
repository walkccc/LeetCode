class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size();
    const int n = board[0].size();

    function<bool(int, int, int)> dfs = [&](int i, int j, int s) {
      if (i < 0 || i == m || j < 0 || j == n) return false;
      if (board[i][j] != word[s] || board[i][j] == '*') return false;
      if (s == word.length() - 1) return true;

      const char cache = board[i][j];
      board[i][j] = '*';
      const bool isExist = dfs(i + 1, j, s + 1) || dfs(i - 1, j, s + 1) ||
                           dfs(i, j + 1, s + 1) || dfs(i, j - 1, s + 1);
      board[i][j] = cache;

      return isExist;
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (dfs(i, j, 0))
          return true;

    return false;
  }
};