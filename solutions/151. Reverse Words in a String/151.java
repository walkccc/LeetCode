class Solution {
  public String reverseWords(String s) {
    StringBuilder sb = new StringBuilder(s).reverse(); // Reverse the whole string.
    reverseWords(sb, sb.length());                     // Reverse each word.
    return cleanSpaces(sb, sb.length());               // Clean up the spaces.
  }

  private void reverseWords(StringBuilder sb, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && sb.charAt(i) == ' ') // Skip the spaces.
        ++i;
      while (j < i || j < n && sb.charAt(j) != ' ') // Skip the spaces.
        ++j;
      reverse(sb, i, j - 1); // Reverse the word.
    }
  }

  // Trim leading, trailing, and middle spaces
  private String cleanSpaces(StringBuilder sb, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && sb.charAt(j) == ' ') // Skip the spaces.
        ++j;
      while (j < n && sb.charAt(j) != ' ') // Keep non spaces
        sb.setCharAt(i++, sb.charAt(j++));
      while (j < n && sb.charAt(j) == ' ') // Skip the spaces.
        ++j;
      if (j < n) // Keep only one space.
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
