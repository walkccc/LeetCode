class Solution {
  public int countLatticePoints(int[][] circles) {
    Set<Pair<Integer, Integer>> points = new HashSet<>();

    // dx := relative to x
    // dy := relative to y
    // So, dx^2 + dy^2 = r^2.
    for (int[] c : circles) {
      final int x = c[0];
      final int y = c[1];
      final int r = c[2];
      for (int dx = -r; dx <= r; ++dx) {
        final int yMax = (int) Math.sqrt(r * r - dx * dx);
        for (int dy = -yMax; dy <= yMax; ++dy)
          points.add(new Pair<>(x + dx, y + dy));
      }
    }

    return points.size();
  }
}
