class Solution {
  public String customSortString(final String S, final String T) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[128];

    for (final char c : T.toCharArray())
      ++count[c];

    for (final char c : S.toCharArray())
      while (count[c]-- > 0)
        sb.append(c);

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        sb.append(c);

    return sb.toString();
  }
}
