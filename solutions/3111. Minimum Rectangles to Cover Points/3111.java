class Solution {
  public int minRectanglesToCoverPoints(int[][] points, int w) {
    int ans = 0;
    int prevX = -w - 1;
    int[] xs = new int[points.length];

    for (int i = 0; i < points.length; ++i)
      xs[i] = points[i][0];

    Arrays.sort(xs);

    for (final int x : xs)
      if (x > prevX + w) {
        ++ans;
        prevX = x;
      }

    return ans;
  }
}
