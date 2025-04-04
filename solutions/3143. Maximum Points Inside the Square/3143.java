class Solution {
  public int maxPointsInsideSquare(int[][] points, String s) {
    int secondMinSize = Integer.MAX_VALUE;
    int[] minSizes = new int[26];
    Arrays.fill(minSizes, Integer.MAX_VALUE);

    for (int i = 0; i < points.length; ++i) {
      final int x = points[i][0];
      final int y = points[i][1];
      final int sz = Math.max(Math.abs(x), Math.abs(y));
      final int j = s.charAt(i) - 'a';
      if (minSizes[j] == Integer.MAX_VALUE) {
        minSizes[j] = sz;
      } else if (sz < minSizes[j]) {
        // This is because minSizes[j] is about to be replaced by a smaller
        // value, so it becomes a candidate for the second minimum size.
        secondMinSize = Math.min(secondMinSize, minSizes[j]);
        minSizes[j] = sz;
      } else {
        // `sz` is not smaller than the current minimum size, but it could be
        // smaller than the current second minimum size.
        secondMinSize = Math.min(secondMinSize, sz);
      }
    }

    final int finalSecondMinSize = secondMinSize;
    return (int) Arrays.stream(minSizes).filter(sz -> sz < finalSecondMinSize).count();
  }
}
