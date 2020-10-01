class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n);
    vector<bool> diag1(2 * n - 1);
    vector<bool> diag2(2 * n - 1);

    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        ans.push_back(board);
        return;
      }

      for (int j = 0; j < n; ++j) {
        if (cols[j] || diag1[i + j] || diag2[j - i + n - 1]) continue;
        board[i][j] = 'Q';
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
        dfs(i + 1);
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
        board[i][j] = '.';
      }
    };

    dfs(0);

    return ans;
  }
};