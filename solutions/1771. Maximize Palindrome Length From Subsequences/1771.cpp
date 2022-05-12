class Solution {
 public:
  int longestPalindrome(string word1, string word2) {
    const string& s = word1 + word2;
    const int n = s.length();
    int ans = 0;
    // dp[i][j] := LPS's length in s[i..j]
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (s[i] == s[j]) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
          if (i < word1.length() && j >= word1.length())
            ans = max(ans, dp[i][j]);
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }

    return ans;
  }
};
