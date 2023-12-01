class Solution {
  public boolean possiblyEquals(String s1, String s2) {
    dp = new Map[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i <= s1.length(); ++i)
      for (int j = 0; j <= s2.length(); ++j)
        dp[i][j] = new HashMap<>();
    return f(s1, s2, 0, 0, 0);
  }

  private Map<Integer, Boolean>[][] dp;

  // Returns true if s1[i..n) matches s2[j..n) with the padding difference.
  // `paddingDiff` := signed padding, if positive, s1 has a positive number of
  // offset bytes relative to s2
  private boolean f(final String s1, final String s2, int i, int j, int paddingDiff) {
    if (dp[i][j].containsKey(paddingDiff))
      return dp[i][j].get(paddingDiff);
    if (i == s1.length() && j == s2.length())
      return paddingDiff == 0;
    if (i < s1.length() && Character.isDigit(s1.charAt(i))) {
      // Add padding on s1.
      final int nextLetterIndex = getNextLetterIndex(s1, i);
      for (final int num : getNums(s1.substring(i, nextLetterIndex)))
        if (f(s1, s2, nextLetterIndex, j, paddingDiff + num))
          return true;
    } else if (j < s2.length() && Character.isDigit(s2.charAt(j))) {
      // Add padding on s2.
      final int nextLetterIndex = getNextLetterIndex(s2, j);
      for (final int num : getNums(s2.substring(j, nextLetterIndex)))
        if (f(s1, s2, i, nextLetterIndex, paddingDiff - num))
          return true;
    } else if (paddingDiff > 0) {
      // `s1` has more padding, so j needs to catch up.
      if (j < s2.length())
        return f(s1, s2, i, j + 1, paddingDiff - 1);
    } else if (paddingDiff < 0) {
      // `s2` has more padding, so i needs to catch up.
      if (i < s1.length())
        return f(s1, s2, i + 1, j, paddingDiff + 1);
    } else { // paddingDiff == 0
      // There's no padding difference, so consume the next letter.
      if (i < s1.length() && j < s2.length() && s1.charAt(i) == s2.charAt(j))
        return f(s1, s2, i + 1, j + 1, 0);
    }
    dp[i][j].put(paddingDiff, false);
    return false;
  }

  private int getNextLetterIndex(final String s, int i) {
    int j = i;
    while (j < s.length() && Character.isDigit(s.charAt(j)))
      ++j;
    return j;
  }

  private List<Integer> getNums(final String s) {
    List<Integer> nums = new ArrayList<>(Arrays.asList(Integer.parseInt(s)));
    if (s.length() == 2) {
      nums.add(Integer.parseInt(s.substring(0, 1)) + Integer.parseInt(s.substring(1, 2)));
    } else if (s.length() == 3) {
      nums.add(Integer.parseInt(s.substring(0, 1)) + Integer.parseInt(s.substring(1, 3)));
      nums.add(Integer.parseInt(s.substring(0, 2)) + Integer.parseInt(s.substring(2, 3)));
      nums.add(Integer.parseInt(s.substring(0, 1)) + Integer.parseInt(s.substring(1, 2)) +
               Integer.parseInt(s.substring(2, 3)));
    }
    return nums;
  }
}
