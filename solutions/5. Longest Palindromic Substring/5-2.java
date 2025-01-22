class Solution {
  public String longestPalindrome(String s) {
    final String t = join('@' + s + '$', /*delimiter=*/'#');
    final int[] p = manacher(t);
    int maxPalindromeLength = 0;
    int bestCenter = -1;

    for (int i = 0; i < p.length; ++i)
      if (p[i] > maxPalindromeLength) {
        maxPalindromeLength = p[i];
        bestCenter = i;
      }

    final int l = (bestCenter - maxPalindromeLength) / 2;
    final int r = (bestCenter + maxPalindromeLength) / 2;
    return s.substring(l, r);
  }

  // Returns an array `p` s.t. `p[i]` is the length of the longest palindrome
  // centered at `t[i]`, where `t` is a string with delimiters and sentinels.
  private int[] manacher(final String t) {
    int[] p = new int[t.length()];
    int center = 0;
    for (int i = 1; i < t.length() - 1; ++i) {
      int rightBoundary = center + p[center];
      int mirrorIndex = center - (i - center);
      if (rightBoundary > i)
        p[i] = Math.min(rightBoundary - i, p[mirrorIndex]);
      // Try to expand the palindrome centered at i.
      while (i + 1 + p[i] < t.length() && i - 1 - p[i] >= 0 &&
             t.charAt(i + 1 + p[i]) == t.charAt(i - 1 - p[i]))
        ++p[i];
      // If a palindrome centered at i expands past `rightBoundary`, adjust
      // the center based on the expanded palindrome.
      if (i + p[i] > rightBoundary) {
        center = i;
      }
    }
    return p;
  }

  private String join(final String s, char delimiter) {
    StringBuilder joined = new StringBuilder();
    for (int i = 0; i < s.length() - 1; ++i) {
      joined.append(s.charAt(i));
      joined.append(delimiter);
    }
    joined.append(s.charAt(s.length() - 1));
    return joined.toString();
  }
}
