class Solution {
  public int countGoodRectangles(int[][] rectangles) {
    int[] minSides = new int[rectangles.length];

    for (int i = 0; i < rectangles.length; ++i) {
      final int x = rectangles[i][0];
      final int y = rectangles[i][1];
      minSides[i] = Math.min(x, y);
    }

    final int maxLen = Arrays.stream(minSides).max().getAsInt();
    return (int) Arrays.stream(minSides).filter(minSide -> minSide == maxLen).count();
  }
}
