class Solution {
  public boolean validPalindrome(String s) {
    for (int l = 0, r = s.length() - 1; l < r; ++l, --r)
      if (s.charAt(l) != s.charAt(r))
        return validPalindrome(s, l + 1, r) || validPalindrome(s, l, r - 1);
    return true;
  }

  private boolean validPalindrome(final String s, int l, int r) {
    while (l < r)
      if (s.charAt(l++) != s.charAt(r--))
        return false;
    return true;
  }
}
