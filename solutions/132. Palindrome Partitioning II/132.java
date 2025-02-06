class Solution {
  public int minCut(String s) {
    final int n = s.length();
    // isPalindrome[i][j] := true if s[i..j] is a palindrome
    boolean[][] isPalindrome = new boolean[n][n];
    for (boolean[] row : isPalindrome)
      Arrays.fill(row, true);
    // dp[i] := the minimum cuts needed for a palindrome partitioning of s[0..i]
    int[] dp = new int[n];
    Arrays.fill(dp, n);

    for (int l = 2; l <= n; ++l)
      for (int i = 0, j = l - 1; j < n; ++i, ++j)
        isPalindrome[i][j] = s.charAt(i) == s.charAt(j) && isPalindrome[i + 1][j - 1];

    for (int i = 0; i < n; ++i) {
      if (isPalindrome[0][i]) {
        dp[i] = 0;
        continue;
      }

      // Try all the possible partitions.
      for (int j = 0; j < i; ++j)
        if (isPalindrome[j + 1][i])
          dp[i] = Math.min(dp[i], dp[j] + 1);
    }

    return dp[n - 1];
  }
}
