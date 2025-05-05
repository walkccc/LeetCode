class Solution {
  public String modifyString(String s) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) == '?')
        sb.append(nextAvailable(sb, s, i));
      else
        sb.append(s.charAt(i));

    return sb.toString();
  }

  private char nextAvailable(StringBuilder sb, final String s, int i) {
    char c = 'a';
    while ((i > 0 && sb.charAt(i - 1) == c) || (i + 1 < s.length() && c == s.charAt(i + 1)))
      ++c;
    return c;
  }
}
