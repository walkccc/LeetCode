class Solution {
 public:
  int strangePrinter(string s) {
    const int n = s.length();
    // dp[i][j] := min # of turns to print s[i..j]
    dp.resize(n, vector<int>(n));
    return strangePrinter(s, 0, n - 1);
  }

 private:
  vector<vector<int>> dp;

  int strangePrinter(const string& s, int i, int j) {
    if (i > j)
      return 0;
    if (dp[i][j])
      return dp[i][j];

    // print s[i]
    dp[i][j] = strangePrinter(s, i + 1, j) + 1;

    for (int k = i + 1; k <= j; ++k)
      if (s[k] == s[i])
        dp[i][j] = min(dp[i][j], strangePrinter(s, i, k - 1) +
                                     strangePrinter(s, k + 1, j));

    return dp[i][j];
  }
};
