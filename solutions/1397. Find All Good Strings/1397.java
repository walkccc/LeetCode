class Solution {
  public int findGoodStrings(int n, String s1, String s2, String evil) {
    Integer[][][][] mem = new Integer[n][evil.length()][2][2];
    // nextMatchedCount[i][j] := the number of next matched evil count, where
    // there're j matches with `evil` and the current letter is ('a' + j)
    Integer[][] nextMatchedCount = new Integer[evil.length()][26];
    return count(s1, s2, evil, 0, 0, true, true, getLPS(evil), nextMatchedCount, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of good strings for s[i..n), where there're j matches
  // with `evil`, `isS1Prefix` indicates if the current letter is tightly bound
  // for `s1` and `isS2Prefix` indicates if the current letter is tightly bound
  // for `s2`.
  private int count(final String s1, final String s2, final String evil, int i,
                    int matchedEvilCount, boolean isS1Prefix, boolean isS2Prefix, int[] evilLPS,
                    Integer[][] nextMatchedCount, Integer[][][][] mem) {
    // s[0..i) contains `evil`, so don't consider any ongoing strings.
    if (matchedEvilCount == evil.length())
      return 0;
    // Run out of strings, so contribute one.
    if (i == s1.length())
      return 1;
    final int k1 = isS1Prefix ? 1 : 0;
    final int k2 = isS2Prefix ? 1 : 0;
    if (mem[i][matchedEvilCount][k1][k2] != null)
      return mem[i][matchedEvilCount][k1][k2];
    mem[i][matchedEvilCount][k1][k2] = 0;
    final char minChar = isS1Prefix ? s1.charAt(i) : 'a';
    final char maxChar = isS2Prefix ? s2.charAt(i) : 'z';
    for (char c = minChar; c <= maxChar; ++c) {
      final int nextMatchedEvilCount =
          getNextMatchedEvilCount(nextMatchedCount, evil, matchedEvilCount, c, evilLPS);
      mem[i][matchedEvilCount][k1][k2] +=
          count(s1, s2, evil, i + 1, nextMatchedEvilCount, isS1Prefix && c == s1.charAt(i),
                isS2Prefix && c == s2.charAt(i), evilLPS, nextMatchedCount, mem);
      mem[i][matchedEvilCount][k1][k2] %= kMod;
    }
    return mem[i][matchedEvilCount][k1][k2];
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

  // j := the next index we're trying to match with `currLetter`
  private int getNextMatchedEvilCount(Integer[][] nextMatchedCount, final String evil, int j,
                                      char currChar, int[] lps) {
    if (nextMatchedCount[j][currChar - 'a'] != null)
      return nextMatchedCount[j][currChar - 'a'];
    while (j > 0 && evil.charAt(j) != currChar)
      j = lps[j - 1];
    return nextMatchedCount[j][currChar - 'a'] = (evil.charAt(j) == currChar ? j + 1 : j);
  }
}
