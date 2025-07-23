class Solution {
 public:
  int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
    const int m = source.length();
    const int n = pattern.length();
    const unordered_set<int> target{targetIndices.begin(), targetIndices.end()};
    // dp[i][j] := the maximum number of operations that can be performed for
    // source[i..m) and pattern[j..n)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
    dp[m][n] = 0;

    for (int i = m - 1; i >= 0; --i) {
      dp[i][n] = (target.contains(i) ? 1 : 0) + dp[i + 1][n];
      for (int j = n - 1; j >= 0; --j) {
        const int pick = source[i] == pattern[j] ? dp[i + 1][j + 1] : INT_MIN;
        const int skip = (target.contains(i) ? 1 : 0) + dp[i + 1][j];
        dp[i][j] = max(pick, skip);
      }
    }

    return dp[0][0] == INT_MIN ? 0 : dp[0][0];
  }
};
