class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();
    // dp[i][j][k] := the length of LPS(s[i..j]) with the previous letter
    // (a' + k)
    dp.resize(n, vector<vector<int>>(n, vector<int>(27)));
    return lps(s, 0, n - 1, 26);
  }

 private:
  vector<vector<vector<int>>> dp;

  int lps(const string& s, int i, int j, int k) {
    if (i >= j)
      return 0;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];

    if (s[i] == s[j] && s[i] != 'a' + k)
      dp[i][j][k] = lps(s, i + 1, j - 1, s[i] - 'a') + 2;
    else
      dp[i][j][k] = max(lps(s, i + 1, j, k), lps(s, i, j - 1, k));

    return dp[i][j][k];
  }
};
