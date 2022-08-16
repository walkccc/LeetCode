class Solution {
  public String reverseWords(String s) {
    StringBuilder sb = new StringBuilder(s).reverse(); // reverse the whole string
    reverseWords(sb, sb.length());                     // reverse each word
    return cleanSpaces(sb, sb.length());               // clean up spaces
  }

  private void reverseWords(StringBuilder sb, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && sb.charAt(i) == ' ') // skip spaces
        ++i;
      while (j < i || j < n && sb.charAt(j) != ' ') // skip non spaces
        ++j;
      reverse(sb, i, j - 1); // reverse the word
    }
  }

  // trim leading, trailing, and middle spaces
  private String cleanSpaces(StringBuilder sb, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && sb.charAt(j) == ' ') // skip spaces
        ++j;
      while (j < n && sb.charAt(j) != ' ') // keep non spaces
        sb.setCharAt(i++, sb.charAt(j++));
      while (j < n && sb.charAt(j) == ' ') // skip spaces
        ++j;
      if (j < n) // keep only one space
        sb.setCharAt(i++, ' ');
    }

    return sb.substring(0, i).toString();
  }

  private void reverse(StringBuilder sb, int l, int r) {
    while (l < r) {
      final char temp = sb.charAt(l);
      sb.setCharAt(l++, sb.charAt(r));
      sb.setCharAt(r--, temp);
    }
  }
}
