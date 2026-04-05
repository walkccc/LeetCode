class Solution {
 public:
  // Similar to 516. Longest Palindromic Subsequence
  int longestPalindromicSubsequence(string s, int k) {
    const int n = s.length();
    // dp[i][j][op] := the length of LPS(s[i..j]) with at most `op` operations
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(n, vector<int>(k + 1)));

    for (int i = 0; i < n; ++i)
      for (int op = 0; op <= k; ++op)
        dp[i][i][op] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        for (int op = 0; op <= k; ++op) {
          if (s[i] == s[j]) {
            dp[i][j][op] = 2 + dp[i + 1][j - 1][op];
          } else {
            dp[i][j][op] = max(dp[i + 1][j][op], dp[i][j - 1][op]);
            const int cost = getCost(s[i], s[j]);
            if (cost <= op)
              dp[i][j][op] = max(dp[i][j][op], 2 + dp[i + 1][j - 1][op - cost]);
          }
        }
      }

    return dp[0][n - 1][k];
  }

 private:
  int getCost(char a, char b) {
    const int dist = abs(a - b);
    return min(dist, 26 - dist);
  }
};
