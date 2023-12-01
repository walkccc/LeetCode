class Solution {
  public String shortestCommonSupersequence(String str1, String str2) {
    StringBuilder sb = new StringBuilder();
    int i = 0; // str1's index
    int j = 0; // str2's index

    for (final char c : lcs(str1, str2).toCharArray()) {
      // Append the letters that are not part of the LCS.
      while (str1.charAt(i) != c)
        sb.append(str1.charAt(i++));
      while (str2.charAt(j) != c)
        sb.append(str2.charAt(j++));
      // Append the letter of the LCS and match it with str1 and str2.
      sb.append(c);
      ++i;
      ++j;
    }

    // Append the remaining letters.
    return sb.toString() + str1.substring(i) + str2.substring(j);
  }

  private String lcs(final String A, final String B) {
    final int m = A.length();
    final int n = B.length();
    // dp[i][j] := the length of LCS(A[0..i), B[0..j))
    StringBuilder[][] dp = new StringBuilder[m + 1][n + 1];

    for (final StringBuilder[] row : dp)
      for (int i = 0; i < row.length; ++i)
        row[i] = new StringBuilder();

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (A.charAt(i - 1) == B.charAt(j - 1))
          dp[i][j].append(dp[i - 1][j - 1]).append(A.charAt(i - 1));
        else
          dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];

    return dp[m][n].toString();
  }
}
