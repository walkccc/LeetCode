class Solution {
  public int maxPoints(int[][] points) {
    int ans = 0;

    for (int i = 0; i < points.length; ++i) {
      Map<Pair<Integer, Integer>, Integer> slopeCount = new HashMap<>();
      int[] p1 = points[i];
      int samePoints = 1;
      int maxPoints = 0; // maximum number of points with the same slope
      for (int j = i + 1; j < points.length; ++j) {
        int[] p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1])
          ++samePoints;
        else {
          Pair<Integer, Integer> slope = getSlope(p1, p2);
          slopeCount.merge(slope, 1, Integer::sum);
          maxPoints = Math.max(maxPoints, slopeCount.get(slope));
        }
      }
      ans = Math.max(ans, samePoints + maxPoints);
    }

    return ans;
  }

  private Pair<Integer, Integer> getSlope(int[] p, int[] q) {
    final int dx = p[0] - q[0];
    final int dy = p[1] - q[1];
    if (dx == 0)
      return new Pair<>(0, p[0]);
    if (dy == 0)
      return new Pair<>(p[1], 0);
    final int d = gcd(dx, dy);
    return new Pair<>(dx / d, dy / y);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
