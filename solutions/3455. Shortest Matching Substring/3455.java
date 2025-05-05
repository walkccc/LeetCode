class Solution {
  public int shortestMatchingSubstring(String s, String p) {
    final String[] parts = split(p);
    final String a = parts[0];
    final String b = parts[1];
    final String c = parts[2];
    final int ns = s.length();
    final int na = a.length();
    final int nb = b.length();
    final int nc = c.length();
    int[] lpsA = getLPS(a + "#" + s);
    int[] lpsB = getLPS(b + "#" + s);
    int[] lpsC = getLPS(c + "#" + s);
    int ans = Integer.MAX_VALUE;

    for (int i = 0, j = 0, k = 0; i + nb + nc < ns; ++i) {
      while (i < ns && lpsA[na + 1 + i] != na)
        ++i;
      while (j < ns && (j < i + nb || lpsB[nb + 1 + j] != nb))
        ++j;
      while (k < ns && (k < j + nc || lpsC[nc + 1 + k] != nc))
        ++k;
      if (k == ns)
        break;
      ans = Math.min(ans, k - i + na);
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  private int[] getLPS(String pattern) {
    int[] lps = new int[pattern.length()];
    for (int i = 1, j = 0; i < pattern.length(); ++i) {
      while (j > 0 && pattern.charAt(j) != pattern.charAt(i))
        j = lps[j - 1];
      if (pattern.charAt(i) == pattern.charAt(j))
        lps[i] = ++j;
    }
    return lps;
  }

  private String[] split(final String p) {
    final int i = p.indexOf('*');
    final int j = p.indexOf('*', i + 1);
    return new String[] {p.substring(0, i), p.substring(i + 1, j), p.substring(j + 1)};
  }
}
