class Solution {
  public long maxScore(int[] points, int m) {
    long l = 0;
    long r = ((long) m + 1) / 2 * points[0] + 1;

    while (l < r) {
      final long mid = (l + r + 1) / 2;
      if (isPossible(points, mid, m))
        l = mid;
      else
        r = mid - 1;
    }

    return l;
  }

  // Returns true if it is possible to achieve the maximum minimum value `x`
  // with `m` number of moves.
  private boolean isPossible(int[] points, long minVal, long m) {
    long moves = 0;
    long prevMoves = 0; // to track remaining moves from the previous point
    for (int i = 0; i < points.length; ++i) {
      // ceil(minVal / point)
      final long required = Math.max(0, (minVal + points[i] - 1) / points[i] - prevMoves);
      if (required > 0) {
        moves += 2L * required - 1;
        prevMoves = required - 1;
      } else if (i + 1 < points.length) {
        moves += 1;
        prevMoves = 0;
      }
      if (moves > m)
        return false;
    }
    return true;
  }
}
