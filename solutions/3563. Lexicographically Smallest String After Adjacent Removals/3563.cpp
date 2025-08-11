class Solution {
 public:
  string lexicographicallySmallestString(string s) {
    const int n = s.size();
    // dp[i][j] := the lexicographically smallest string by removing adjacent
    // letters from s[i..j)
    vector<vector<string>> dp(n + 1, vector<string>(n + 1));

    for (int d = 1; d <= n; ++d)
      for (int i = 0; i + d <= n; ++i) {
        const int j = i + d;
        // 1. Keep s[i].
        string minString = s[i] + dp[i + 1][j];
        // 2. Remove s[i] and s[k] if possible.
        for (int k = i + 1; k < j; ++k)
          if (isConsecutive(s[i], s[k]) && dp[i + 1][k].empty())
            minString = min(minString, dp[k + 1][j]);
        dp[i][j] = minString;
      }

    return dp[0][n];
  }

 private:
  bool isConsecutive(char a, char b) {
    return abs(a - b) == 1 || abs(a - b) == 25;
  }
};
