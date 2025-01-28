class Solution {
  public int minimumLines(int[][] stockPrices) {
    int ans = 0;

    Arrays.sort(stockPrices, (a, b) -> Integer.compare(a[0], b[0]));

    for (int i = 2; i < stockPrices.length; ++i) {
      Pair<Integer, Integer> a = getSlope(stockPrices[i - 2], stockPrices[i - 1]);
      Pair<Integer, Integer> b = getSlope(stockPrices[i - 1], stockPrices[i]);
      if (a.getKey() != b.getKey() || a.getValue() != b.getValue())
        ++ans;
    }

    return ans + (stockPrices.length > 1 ? 1 : 0);
  }

  private Pair<Integer, Integer> getSlope(int[] p, int[] q) {
    final int dx = p[0] - q[0];
    final int dy = p[1] - q[1];
    if (dx == 0)
      return new Pair<>(0, p[0]);
    if (dy == 0)
      return new Pair<>(p[1], 0);
    final int d = gcd(dx, dy);
    return new Pair<>(dx / d, dy / d);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
