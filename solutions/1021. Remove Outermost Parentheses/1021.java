class Solution {
  public String removeOuterParentheses(String s) {
    StringBuilder sb = new StringBuilder();
    int opened = 0;

    for (final char c : s.toCharArray())
      if (c == '(') {
        if (++opened > 1)
          sb.append(c);
      } else if (--opened > 0) { // c == ')'
        sb.append(c);
      }

    return sb.toString();
  }
}
