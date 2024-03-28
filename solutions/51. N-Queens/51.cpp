class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    dfs(n, 0, vector<bool>(n), vector<bool>(2 * n - 1), vector<bool>(2 * n - 1),
        vector<string>(n, string(n, '.')), ans);
    return ans;
  }

 private:
  void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,
           vector<bool>&& diag2, vector<string>&& board,
           vector<vector<string>>& ans) {
    if (i == n) {
      ans.push_back(board);
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
        continue;
      board[i][j] = 'Q';
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
      dfs(n, i + 1, move(cols), move(diag1), move(diag2), move(board), ans);
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
      board[i][j] = '.';
    }
  }
};
