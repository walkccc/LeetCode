class Solution {
  public int minimumLines(int[][] points) {
    final int allCovered = (1 << points.length) - 1;
    int[] memo = new int[allCovered];
    Arrays.fill(memo, -1);
    return dfs(points, 0, allCovered, memo);
  }

  private int dfs(int[][] points, int covered, int allCovered, int[] memo) {
    if (covered == allCovered)
      return 0;
    if (memo[covered] != -1)
      return memo[covered];

    final int n = points.length;
    int ans = n / 2 + ((n & 1) == 1 ? 1 : 0);

    for (int i = 0; i < n; ++i) {
      if ((covered >> i & 1) == 1)
        continue;
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        // connect points[i] with points[j]
        int newCovered = covered | 1 << i | 1 << j;
        // mark points covered by this line
        Pair<Integer, Integer> slope = getSlope(points[i], points[j]);
        for (int k = 0; k < n; ++k)
          if (getSlope(points[i], points[k]).equals(slope))
            newCovered |= 1 << k;
        ans = Math.min(ans, 1 + dfs(points, newCovered, allCovered, memo));
      }
    }

    return memo[covered] = ans;
  }

  private Pair<Integer, Integer> getSlope(int[] p, int[] q) {
    final int dx = p[0] - q[0];
    final int dy = p[1] - q[1];
    if (dx == 0)
      return new Pair<>(0, p[0]);
    if (dy == 0)
      return new Pair<>(p[1], 0);
    final int d = gcd(dx, dy);
    final int x = dx / d;
    final int y = dy / d;
    return x > 0 ? new Pair<>(x, y) : new Pair<>(-x, -y);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
