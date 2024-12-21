class Solution {
  public int wordsTyping(String[] sentence, int rows, int cols) {
    final String combined = String.join(" ", sentence) + " ";
    final int n = combined.length();
    int i = 0; // (i % n) points to the index of combined in each row

    while (rows-- > 0) {
      i += cols;
      if (combined.charAt(i % n) == ' ') {
        ++i;
      } else {
        while (i > 0 && combined.charAt((i - 1) % n) != ' ')
          --i;
      }
    }

    return i / n;
  }
}
