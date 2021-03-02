class Solution {
  public int wordsTyping(String[] sentence, int rows, int cols) {
    StringBuilder combined = getCombined(sentence);
    final int n = combined.length();

    int start = 0; // the start index of combined in each row

    for (int i = 0; i < rows; ++i) {
      start += cols;
      if (combined.charAt(start % n) == ' ') {
        ++start;
      } else {
        while (start > 0 && combined.charAt((start - 1) % n) != ' ')
          --start;
      }
    }

    return start / n;
  }

  private StringBuilder getCombined(final String[] sentence) {
    StringBuilder sb = new StringBuilder();
    for (final String word : sentence)
      sb.append(word).append(' ');
    return sb;
  }
}
