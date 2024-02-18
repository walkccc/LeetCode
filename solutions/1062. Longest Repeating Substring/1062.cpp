class Solution {
 public:
  int longestRepeatingSubstring(string s) {
    const int n = s.length();
    int ans = 0;
    // dp[i][j] := the number of repeating characters of s[0..i) and s[0..j)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }

    return ans;
  }
};
