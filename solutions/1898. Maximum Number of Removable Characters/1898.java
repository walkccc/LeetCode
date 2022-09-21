class Solution {
  public int maximumRemovals(String s, String p, int[] removable) {
    int l = 0;
    int r = removable.length + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      final String removed = remove(s, removable, m);
      if (isSubsequence(p, removed))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

  private String remove(final String s, int[] removable, int k) {
    StringBuilder sb = new StringBuilder(s);
    for (int i = 0; i < k; ++i)
      sb.setCharAt(removable[i], '*');
    return sb.toString();
  }

  private boolean isSubsequence(final String p, final String s) {
    int i = 0; // p's index
    for (int j = 0; j < s.length(); ++j)
      if (p.charAt(i) == s.charAt(j))
        if (++i == p.length())
          return true;
    return false;
  }
}
