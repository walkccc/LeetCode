class Solution {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    string ans;
    int i = 0;  // str1's index
    int j = 0;  // str2's index

    for (const char c : lcs(str1, str2)) {
      // Append the letters that are not part of the LCS.
      while (str1[i] != c)
        ans += str1[i++];
      while (str2[j] != c)
        ans += str2[j++];
      // Append the letter of the LCS and match it with str1 and str2.
      ans += c;
      ++i;
      ++j;
    }

    // Append the remaining letters.
    return ans + str1.substr(i) + str2.substr(j);
  }

 private:
  string lcs(const string& A, const string& B) {
    const int m = A.length();
    const int n = B.length();
    // dp[i][j] := the length of LCS(A[0..i), B[0..j))
    vector<vector<string>> dp(m + 1, vector<string>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (A[i - 1] == B[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
        else
          dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length()
                         ? dp[i - 1][j]
                         : dp[i][j - 1];

    return dp[m][n];
  }
};
