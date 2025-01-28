class Solution {
  public String capitalizeTitle(String title) {
    StringBuilder sb = new StringBuilder(title.toLowerCase());

    int i = 0; // Point to the start of a word.
    int j = 0; // Point to the end of a word.

    while (j < sb.length()) {
      while (j < sb.length() && sb.charAt(j) != ' ')
        ++j;
      if (j - i > 2)
        sb.setCharAt(i, Character.toUpperCase(sb.charAt(i)));
      i = j + 1;
      ++j; // Skip the spaces.
    }

    return sb.toString();
  }
}
