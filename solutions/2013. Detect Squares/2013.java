class DetectSquares {
  public void add(int[] point) {
    pointCount.merge(hash(point[0], point[1]), 1, Integer::sum);
  }

  public int count(int[] point) {
    final int x1 = point[0];
    final int y1 = point[1];
    int ans = 0;

    for (final int hashed : pointCount.keySet()) {
      final int count = pointCount.get(hashed);
      final int x3 = hashed >> 10;
      final int y3 = hashed & 1023;
      if (x1 != x3 && Math.abs(x1 - x3) == Math.abs(y1 - y3)) {
        final int p = hash(x1, y3);
        final int q = hash(x3, y1);
        if (pointCount.containsKey(p) && pointCount.containsKey(q))
          ans += count * pointCount.get(p) * pointCount.get(q);
      }
    }

    return ans;
  }

  private Map<Integer, Integer> pointCount = new HashMap<>();

  private int hash(int i, int j) {
    return i << 10 | j;
  }
}
