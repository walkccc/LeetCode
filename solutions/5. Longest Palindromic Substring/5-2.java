class Solution {
  public String longestPalindrome(String s) {
    // '@' and '$' signs serve as sentinels appended to each end to avoid bounds
    // checking.
    final String t = join('@' + s + '$', '#');
    final int n = t.length();
    // t[i - maxExtends[i]..i) ==
    // t[i + 1..i + maxExtends[i]]
    int[] maxExtends = new int[n];
    int center = 0;

    for (int i = 1; i < n - 1; ++i) {
      final int rightBoundary = center + maxExtends[center];
      final int mirrorIndex = center - (i - center);
      maxExtends[i] =
          rightBoundary > i && Math.min(rightBoundary - i, maxExtends[mirrorIndex]) > 0 ? 1 : 0;

      // Attempt to expand the palindrome centered at i.
      while (t.charAt(i + 1 + maxExtends[i]) == t.charAt(i - 1 - maxExtends[i]))
        ++maxExtends[i];

      // If a palindrome centered at i expand past `rightBoundary`, adjust
      // center based on expanded palindrome.
      if (i + maxExtends[i] > rightBoundary)
        center = i;
    }

    // Find `maxExtend` and `bestCenter`.
    int maxExtend = 0;
    int bestCenter = -1;

    for (int i = 0; i < n; ++i)
      if (maxExtends[i] > maxExtend) {
        maxExtend = maxExtends[i];
        bestCenter = i;
      }

    return s.substring((bestCenter - maxExtend) / 2, (bestCenter + maxExtend) / 2);
  }

  private String join(final String s, char c) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.length(); ++i) {
      sb.append(s.charAt(i));
      if (i != s.length() - 1)
        sb.append(c);
    }
    return sb.toString();
  }
}
