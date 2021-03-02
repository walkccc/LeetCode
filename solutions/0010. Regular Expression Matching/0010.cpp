class Solution {
 public:
  bool isMatch(string s, string p) {
    const int m = s.length();
    const int n = p.length();

    // dp[i][j] := true if s[0..i) matches p[0..j)
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;

    auto isMatch = [](char c1, char c2) { return c1 == c2 || c2 == '.'; };

    for (int i = 0; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (p[j - 1] == '*') {
          const bool noRepeat = dp[i][j - 2];
          const bool doRepeat =
              i && isMatch(s[i - 1], p[j - 2]) && dp[i - 1][j];
          dp[i][j] = noRepeat || doRepeat;
        } else {
          dp[i][j] = i && isMatch(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
        }

    return dp[m][n];
  }
};
