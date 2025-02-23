class Solution {
  public boolean checkPartitioning(String s) {
    final int n = s.length();
    Boolean[][] mem = new Boolean[n][n];

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j + 1 < n; ++j)
        if (isPalindrome(s, 0, i, mem) &&     //
            isPalindrome(s, i + 1, j, mem) && //
            isPalindrome(s, j + 1, n - 1, mem))
          return true;

    return false;
  }

  // Returns true if s[i..j] is a palindrome.
  // Returns false if s[i..j] is not a palindrome.
  private boolean isPalindrome(final String s, int i, int j, Boolean[][] mem) {
    if (i > j)
      return true;
    if (mem[i][j] != null)
      return mem[i][j];
    if (s.charAt(i) == s.charAt(j))
      return mem[i][j] = isPalindrome(s, i + 1, j - 1, mem);
    return mem[i][j] = false;
  }
}
