class Solution {
 public:
  int deleteString(string s) {
    const int n = s.length();
    // lcs[i][j] := # of the same characters of s[i:] and s[j:]
    vector<vector<int>> lcs(n + 1, vector<int>(n + 1));
    // dp[i] := max # of operations needed to delete s[i:]
    vector<int> dp(n, 1);

    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j])
          lcs[i][j] = lcs[i + 1][j + 1] + 1;
        if (lcs[i][j] >= j - i)
          dp[i] = max(dp[i], dp[j] + 1);
      }

    return dp[0];
  }
};
