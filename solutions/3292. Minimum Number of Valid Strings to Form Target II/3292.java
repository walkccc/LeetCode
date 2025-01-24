class Solution {
  // 3291. Minimum Number of Valid Strings to Form Target I
  public int minValidStrings(String[] words, String target) {
    int ans = 0;
    int unmatchedPrefix = target.length();
    int[][] lpsList = new int[words.length][];

    for (int i = 0; i < words.length; ++i)
      lpsList[i] = getLPS(words[i] + '#' + target);

    while (unmatchedPrefix > 0) {
      // Greedily choose the word that has the longest suffix match with the
      // remaining unmatched prefix.
      int maxMatchSuffix = 0;
      for (int i = 0; i < words.length; ++i)
        maxMatchSuffix = Math.max(maxMatchSuffix, lpsList[i][words[i].length() + unmatchedPrefix]);
      if (maxMatchSuffix == 0)
        return -1;
      ++ans;
      unmatchedPrefix -= maxMatchSuffix;
    }

    return ans;
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  private int[] getLPS(final String pattern) {
    int[] lps = new int[pattern.length()];
    for (int i = 1, j = 0; i < pattern.length(); ++i) {
      while (j > 0 && pattern.charAt(j) != pattern.charAt(i))
        j = lps[j - 1];
      if (pattern.charAt(i) == pattern.charAt(j))
        lps[i] = ++j;
    }
    return lps;
  }
}
