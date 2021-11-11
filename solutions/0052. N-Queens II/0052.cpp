class Solution {
 public:
  int totalNQueens(int n) {
    int ans = 0;
    vector<bool> cols(n);
    vector<bool> diag1(2 * n - 1);
    vector<bool> diag2(2 * n - 1);

    dfs(n, 0, cols, diag1, diag2, ans);

    return ans;
  }

 private:
  void dfs(int n, int i, vector<bool>& cols, vector<bool>& diag1,
           vector<bool>& diag2, int& ans) {
    if (i == n) {
      ++ans;
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
        continue;
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
      dfs(n, i + 1, cols, diag1, diag2, ans);
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
    }
  }
};
