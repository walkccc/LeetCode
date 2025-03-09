class Solution {
  public String reverseWords(String s) {
    StringBuilder sb = new StringBuilder(s);
    int i = 0;
    int j = 0;

    while (i < sb.length()) {
      while (i < j || i < sb.length() && sb.charAt(i) == ' ')
        ++i;
      while (j < i || j < sb.length() && sb.charAt(j) != ' ')
        ++j;
      reverse(sb, i, j - 1);
    }

    return sb.toString();
  }

  private void reverse(StringBuilder sb, int l, int r) {
    while (l < r) {
      final char temp = sb.charAt(l);
      sb.setCharAt(l++, sb.charAt(r));
      sb.setCharAt(r--, temp);
    }
  }
}
