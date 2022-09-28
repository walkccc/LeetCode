class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> memo(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = max(ans, dfs(matrix, i, j, INT_MIN, memo));

    return ans;
  }

 private:
  // memo[i][j] := the LIP starting from matrix[i][j]
  int dfs(const vector<vector<int>>& matrix, int i, int j, int prev,
          vector<vector<int>>& memo) {
    if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size())
      return 0;
    if (matrix[i][j] <= prev)
      return 0;
    int& ans = memo[i][j];
    if (ans)
      return ans;

    const int curr = matrix[i][j];
    return ans = 1 + max({dfs(matrix, i + 1, j, curr, memo),
                          dfs(matrix, i - 1, j, curr, memo),
                          dfs(matrix, i, j + 1, curr, memo),
                          dfs(matrix, i, j - 1, curr, memo)});
  }
};
