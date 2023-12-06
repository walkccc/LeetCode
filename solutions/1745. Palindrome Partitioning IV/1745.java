class Solution {
  public boolean checkPartitioning(String s) {
    final int n = s.length();
    // dp[i][j] := true if s[i..j] is a palindrome
    dp = new int[n][n];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (isPalindrome(s, 0, i) == 1 && isPalindrome(s, i + 1, j) == 1 &&
            isPalindrome(s, j + 1, n - 1) == 1)
          return true;

    return false;
  }

  private int[][] dp;

  // Returns 0 if s[i..j] is not a palindrome
  // Returns 1 if s[i..j] is a palindrome
  int isPalindrome(final String s, int i, int j) {
    if (i > j)
      return 1;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s.charAt(i) == s.charAt(j))
      return dp[i][j] = isPalindrome(s, i + 1, j - 1);
    return dp[i][j] = 0;
  }
}
