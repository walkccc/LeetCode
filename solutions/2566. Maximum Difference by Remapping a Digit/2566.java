class Solution {
  public int minMaxDifference(int num) {
    final String s = String.valueOf(num);
    final char to9 = s.charAt(firstNotNineIndex(s));
    final char to0 = s.charAt(0);
    return getMax(new StringBuilder(s), to9) - getMin(new StringBuilder(s), to0);
  }

  private int firstNotNineIndex(final String s) {
    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) != '9')
        return i;
    return 0;
  }

  private int getMax(StringBuilder sb, char to9) {
    for (int i = 0; i < sb.length(); ++i)
      if (sb.charAt(i) == to9)
        sb.setCharAt(i, '9');
    return Integer.parseInt(sb.toString());
  }

  private int getMin(StringBuilder sb, char to0) {
    for (int i = 0; i < sb.length(); ++i)
      if (sb.charAt(i) == to0)
        sb.setCharAt(i, '0');
    return Integer.parseInt(sb.toString());
  }
}
