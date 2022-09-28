class Solution {
  public int expressiveWords(String S, String[] words) {
    int ans = 0;

    for (final String word : words)
      if (isStretchy(S, word))
        ++ans;

    return ans;
  }

  private boolean isStretchy(final String S, final String word) {
    final int n = S.length();
    final int m = word.length();

    int j = 0;
    for (int i = 0; i < n; ++i)
      if (j < m && S.charAt(i) == word.charAt(j))
        ++j;
      else if (i > 1 && S.charAt(i) == S.charAt(i - 1) && S.charAt(i - 1) == S.charAt(i - 2))
        continue;
      else if (0 < i && i + 1 < n &&
          S.charAt(i - 1) == S.charAt(i) &&
          S.charAt(i) == S.charAt(i + 1))
        continue;
      else
        return false;

    return j == m;
  }
}
