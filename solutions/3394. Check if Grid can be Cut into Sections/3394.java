class Solution {
  public boolean checkValidCuts(int n, int[][] rectangles) {
    int[][] xs = new int[rectangles.length][2];
    int[][] ys = new int[rectangles.length][2];

    for (int i = 0; i < rectangles.length; ++i) {
      xs[i][0] = rectangles[i][0];
      xs[i][1] = rectangles[i][2];
      ys[i][0] = rectangles[i][1];
      ys[i][1] = rectangles[i][3];
    }

    return Math.max(countMerged(xs), countMerged(ys)) >= 3;
  }

  private int countMerged(int[][] intervals) {
    int count = 0;
    int prevEnd = 0;

    Arrays.sort(intervals, Comparator.comparingInt((int[] interval) -> interval[0]));

    for (int[] interval : intervals) {
      final int start = interval[0];
      final int end = interval[1];
      if (start < prevEnd) {
        prevEnd = Math.max(prevEnd, end);
      } else {
        prevEnd = end;
        ++count;
      }
    }

    return count;
  }
}
