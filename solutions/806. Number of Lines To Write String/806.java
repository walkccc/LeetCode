class Solution {
  public int[] numberOfLines(int[] widths, String s) {
    int numLines = 1;
    int runningWidth = 0;

    for (final char c : s.toCharArray()) {
      final int width = widths[c - 'a'];
      if (runningWidth + width <= 100) {
        runningWidth += width;
      } else {
        ++numLines;
        runningWidth = width;
      }
    }

    return new int[] {numLines, runningWidth};
  }
}
