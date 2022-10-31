class Solution {
 public:
  int longestRepeatingSubstring(string S) {
    const int n = S.length();
    int ans = 0;
    // dp[i][j] := # of repeating chars of S[0..i) and S[0..j)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (S[i - 1] == S[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }

    return ans;
  }
};
