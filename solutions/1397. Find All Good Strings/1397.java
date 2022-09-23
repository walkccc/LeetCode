class Solution {
  public int findGoodStrings(int n, String s1, String s2, String evil) {
    // dp[i][j][k1][k2] := # of good strings for s[i:] and there're already j
    // matches with `evil`, where k1 is the 0/1 tight constraint for s1 and k2
    // is the 0/1 tight constraint for s2
    dp = new Integer[n][evil.length()][2][2];
    // nextMatchedCount[i][j] := # next matched evil count given that there're
    // already i matches with `evil` and the current char is ('a' + j)
    nextMatchedCount = new Integer[evil.length()][26];
    return find(s1, s2, evil, 0, 0, true, true, getLPS(evil));
  }

  private static final int kMod = 1_000_000_007;
  private Integer[][][][] dp;
  private Integer[][] nextMatchedCount;

  private int find(final String s1, final String s2, final String evil, int i, int matchedEvilCount,
                   boolean isS1Prefix, boolean isS2Prefix, int[] evilLPS) {
    // s[:i] contains `evil`, so don't consider any ongoing strings
    if (matchedEvilCount == evil.length())
      return 0;
    // run out of string, contributes one
    if (i == s1.length())
      return 1;
    final int k1 = isS1Prefix ? 1 : 0;
    final int k2 = isS2Prefix ? 1 : 0;
    if (dp[i][matchedEvilCount][k1][k2] != null)
      return dp[i][matchedEvilCount][k1][k2];
    dp[i][matchedEvilCount][k1][k2] = 0;
    final char minChar = isS1Prefix ? s1.charAt(i) : 'a';
    final char maxChar = isS2Prefix ? s2.charAt(i) : 'z';
    for (char c = minChar; c <= maxChar; ++c) {
      final int nextMatchedEvilCount = getNextMatchedEvilCount(evil, matchedEvilCount, c, evilLPS);
      dp[i][matchedEvilCount][k1][k2] +=
          find(s1, s2, evil, i + 1, nextMatchedEvilCount, isS1Prefix && c == s1.charAt(i),
               isS2Prefix && c == s2.charAt(i), evilLPS);
      dp[i][matchedEvilCount][k1][k2] %= kMod;
    }
    return dp[i][matchedEvilCount][k1][k2];
  }

  // get Longest Prefix also Suffix
  private int[] getLPS(final String s) {
    int[] lps = new int[s.length()];
    for (int i = 1, j = 0; i < s.length(); ++i) {
      while (j > 0 && s.charAt(j) != s.charAt(i))
        j = lps[j - 1];
      if (s.charAt(i) == s.charAt(j))
        lps[i] = ++j;
    }
    return lps;
  }

  // j := the next index we're trying to match with `currChar`
  private int getNextMatchedEvilCount(final String evil, int j, char currChar, int[] lps) {
    if (nextMatchedCount[j][currChar - 'a'] != null)
      return nextMatchedCount[j][currChar - 'a'];
    while (j > 0 && evil.charAt(j) != currChar)
      j = lps[j - 1];
    return nextMatchedCount[j][currChar - 'a'] = (evil.charAt(j) == currChar ? j + 1 : j);
  }
}
