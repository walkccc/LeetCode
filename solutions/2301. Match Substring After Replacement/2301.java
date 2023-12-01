class Solution {
  public boolean matchReplacement(String s, String sub, char[][] mappings) {
    boolean[][] isMapped = new boolean[128][128];

    for (char[] m : mappings) {
      final char old = m[0];
      final char _new = m[1];
      isMapped[old][_new] = true;
    }

    for (int i = 0; i < s.length(); ++i)
      if (canTransform(s, i, sub, isMapped))
        return true;

    return false;
  }

  private boolean canTransform(final String s, int start, final String sub, boolean[][] isMapped) {
    if (start + sub.length() > s.length())
      return false;

    for (int i = 0; i < sub.length(); ++i) {
      final char a = sub.charAt(i);
      final char b = s.charAt(start + i);
      if (a != b && !isMapped[a][b])
        return false;
    }

    return true;
  }
}
