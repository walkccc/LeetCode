class Solution {
 public:
  int totalNQueens(int n) {
    int ans = 0;
    dfs(n, 0, vector<bool>(n), vector<bool>(2 * n - 1), vector<bool>(2 * n - 1),
        ans);
    return ans;
  }

 private:
  void dfs(int n, int i, vector<bool>&& cols, vector<bool>&& diag1,
           vector<bool>&& diag2, int& ans) {
    if (i == n) {
      ++ans;
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
        continue;
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
      dfs(n, i + 1, move(cols), move(diag1), move(diag2), ans);
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
    }
  }
};
