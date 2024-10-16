class Solution {
  public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
    int minSide = 0;

    for (int i = 0; i < bottomLeft.length; ++i)
      for (int j = i + 1; j < bottomLeft.length; ++j) {
        final int ax1 = bottomLeft[i][0];
        final int ay1 = bottomLeft[i][1];
        final int ax2 = topRight[i][0];
        final int ay2 = topRight[i][1];
        final int bx1 = bottomLeft[j][0];
        final int by1 = bottomLeft[j][1];
        final int bx2 = topRight[j][0];
        final int by2 = topRight[j][1];
        final int overlapX = Math.min(ax2, bx2) - Math.max(ax1, bx1);
        final int overlapY = Math.min(ay2, by2) - Math.max(ay1, by1);
        minSide = Math.max(minSide, Math.min(overlapX, overlapY));
      }

    return (long) minSide * minSide;
  }
}
