class Solution {
  public String parseTernary(String expression) {
    final char c = expression.charAt(i);

    if (i + 1 == expression.length() || expression.charAt(i + 1) == ':') {
      i += 2; // Skip ':'s.
      return String.valueOf(c);
    }

    i += 2; // Skip '?'s.
    final String first = parseTernary(expression);
    final String second = parseTernary(expression);
    return c == 'T' ? first : second;
  }

  private int i = 0;
}
