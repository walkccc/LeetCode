class DetectSquares {
  public void add(int[] point) {
    pointCount.merge(getHash(point[0], point[1]), 1, Integer::sum);
  }

  public int count(int[] point) {
    final int x1 = point[0];
    final int y1 = point[1];
    int ans = 0;

    for (final int hash : pointCount.keySet()) {
      final int count = pointCount.get(hash);
      final int x3 = hash >> 10;
      final int y3 = hash & 1023;
      if (x1 != x3 && Math.abs(x1 - x3) == Math.abs(y1 - y3)) {
        final int p = getHash(x1, y3);
        final int q = getHash(x3, y1);
        if (pointCount.containsKey(p) && pointCount.containsKey(q))
          ans += count * pointCount.get(p) * pointCount.get(q);
      }
    }

    return ans;
  }

  private Map<Integer, Integer> pointCount = new HashMap<>();

  private int getHash(int i, int j) {
    return i << 10 | j;
  }
}
