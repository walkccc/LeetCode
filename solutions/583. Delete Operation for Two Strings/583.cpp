class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int k = lcs(word1, word2);
    return (word1.length() - k) + (word2.length() - k);
  }

 private:
  int lcs(const string& a, const string& b) {
    const int m = a.length();
    const int n = b.length();
    // dp[i][j] := the length of LCS(a[0..i), b[0..j))
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (a[i - 1] == b[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
};
