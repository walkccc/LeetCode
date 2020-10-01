class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    const int m = matrix.size();
    const int n = matrix[0].size();

    int ans = 0;
    // memo[i][j] := the LIP starting from matrix[i][j]
    vector<vector<int>> memo(m, vector<int>(n));

    function<int(int, int, int)> dfs = [&](int i, int j, int prev) {
      if (i < 0 || i == m || j < 0 || j == n) return 0;
      if (matrix[i][j] <= prev) return 0;
      int& ans = memo[i][j];
      if (ans) return ans;

      const int curr = matrix[i][j];
      return ans = 1 + max({dfs(i + 1, j, curr), dfs(i - 1, j, curr),
                            dfs(i, j + 1, curr), dfs(i, j - 1, curr)});
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = max(ans, dfs(i, j, INT_MIN));

    return ans;
  }
};