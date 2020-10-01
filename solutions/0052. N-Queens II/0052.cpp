class Solution {
 public:
  int totalNQueens(int n) {
    int ans = 0;
    vector<bool> cols(n);
    vector<bool> diag1(2 * n - 1);
    vector<bool> diag2(2 * n - 1);

    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        ++ans;
        return;
      }

      for (int j = 0; j < n; ++j) {
        if (cols[j] || diag1[i + j] || diag2[j - i + n - 1]) continue;
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
        dfs(i + 1);
        cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
      }
    };

    dfs(0);

    return ans;
  }
};