class Solution {
  public String splitLoopedString(String[] strs) {
    String ans = "";
    String[] sortedStrs = new String[strs.length];

    for (int i = 0; i < strs.length; ++i) {
      final String s = strs[i];
      final String r = new StringBuilder(s).reverse().toString();
      sortedStrs[i] = s.compareTo(r) > 0 ? s : r;
    }

    for (int i = 0; i < sortedStrs.length; ++i)
      for (final String s :
           new String[] {sortedStrs[i], new StringBuilder(sortedStrs[i]).reverse().toString()})
        for (int j = 0; j <= s.length(); ++j) {
          final String t = s.substring(j) + join(sortedStrs, i) + s.substring(0, j);
          if (t.compareTo(ans) > 0)
            ans = t;
        }

    return ans;
  }

  private String join(String[] sortedStrs, int i) {
    StringBuilder sb = new StringBuilder();
    for (int j = i + 1; j < sortedStrs.length; ++j)
      sb.append(sortedStrs[j]);
    for (int j = 0; j < i; ++j)
      sb.append(sortedStrs[j]);
    return sb.toString();
  }
}
