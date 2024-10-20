class Solution {
  public String firstPalindrome(String[] words) {
    for (final String word : words)
      if (isPalindrome(word))
        return word;
    return "";
  }

  private boolean isPalindrome(final String s) {
    int i = 0;
    int j = 0;
    while (i < j)
      if (s.charAt(i++) != s.charAt(j--))
        return false;
    return true;
  }
}
