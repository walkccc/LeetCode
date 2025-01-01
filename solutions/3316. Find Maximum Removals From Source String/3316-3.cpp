class Solution {
 public:
  int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
    const int m = source.length();
    const int n = pattern.length();
    const unordered_set<int> target{targetIndices.begin(), targetIndices.end()};
    // dp[j] := the maximum number of operations that can be performed for
    // source so far and pattern[j..n)
    vector<int> dp(n + 1, INT_MIN);
    dp[n] = 0;

    for (int i = m - 1; i >= 0; --i) {
      vector<int> newDp(dp);
      newDp[n] = (target.contains(i) ? 1 : 0) + dp[n];
      for (int j = n - 1; j >= 0; --j) {
        const int pick = source[i] == pattern[j] ? dp[j + 1] : INT_MIN;
        const int skip = (target.contains(i) ? 1 : 0) + dp[j];
        newDp[j] = max(pick, skip);
      }
      dp = std::move(newDp);
    }

    return dp[0] == INT_MIN ? 0 : dp[0];
  }
};
