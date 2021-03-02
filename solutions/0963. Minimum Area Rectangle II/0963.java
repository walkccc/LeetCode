class Solution {
  public double minAreaFreeRect(int[][] points) {
    Long ans = Long.MAX_VALUE;
    Map<Integer, List<int[]>> centerToPoints = new HashMap<>();

    for (int[] A : points)
      for (int[] B : points) {
        int center = hash(A, B);
        if (centerToPoints.get(center) == null)
          centerToPoints.put(center, new ArrayList<>());
        centerToPoints.get(center).add(new int[] {A[0], A[1], B[0], B[1]});
      }

    for (List<int[]> pointPairs : centerToPoints.values())
      for (int[] ab : pointPairs)
        for (int[] cd : pointPairs) {
          int ax = ab[0], ay = ab[1];
          int cx = cd[0], cy = cd[1], dx = cd[2], dy = cd[3];
          if ((cx - ax) * (dx - ax) + (cy - ay) * (dy - ay) == 0) {
            Long squaredArea = dist(ax, ay, cx, cy) * dist(ax, ay, dx, dy);
            if (squaredArea > 0)
              ans = Math.min(ans, squaredArea);
          }
        }

    return ans == Long.MAX_VALUE ? 0 : Math.sqrt(ans);
  }

  private int hash(int[] p, int[] q) {
    return ((p[0] + q[0]) << 16) + (p[1] + q[1]);
  }

  private Long dist(long px, long py, long qx, long qy) {
    return (px - qx) * (px - qx) + (py - qy) * (py - qy);
  }
}
