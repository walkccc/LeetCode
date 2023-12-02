class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    // dp[i][j] := the length of LPS(s[i..j])
    dp.resize(n, vector<int>(n));
    return lps(s, 0, n - 1);
  }

 private:
  vector<vector<int>> dp;

  int lps(const string& s, int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (dp[i][j] > 0)
      return dp[i][j];

    if (s[i] == s[j])
      dp[i][j] = 2 + lps(s, i + 1, j - 1);
    else
      dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));

    return dp[i][j];
  }
};
