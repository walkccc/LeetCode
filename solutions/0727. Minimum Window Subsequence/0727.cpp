class Solution {
 public:
  string minWindow(string S, string T) {
    const int m = T.length();
    const int n = S.length();
    // dp[i][j] := start index (1-indexed) of
    // the minimum window of T[0..i] and S[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // fill in placeholder values
    for (int j = 0; j <= n; ++j)
      dp[0][j] = j + 1;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (T[i - 1] == S[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = dp[i][j - 1];

    int bestLeft = 0;
    int minLength = INT_MAX;

    for (int j = 1; j <= n; ++j)
      if (dp[m][j] > 0 && j - dp[m][j] + 1 < minLength) {
        bestLeft = dp[m][j] - 1;
        minLength = j - dp[m][j] + 1;
      }

    return minLength == INT_MAX ? "" : S.substr(bestLeft, minLength);
  }
};
