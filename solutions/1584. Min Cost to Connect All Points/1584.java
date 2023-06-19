class Solution {
  public int minCostConnectPoints(int[][] points) {
    // dist[i] := min distance to connect points[i]
    int[] dist = new int[points.length];
    Arrays.fill(dist, Integer.MAX_VALUE);
    int ans = 0;

    for (int i = 0; i < points.length - 1; ++i) {
      for (int j = i + 1; j < points.length; ++j) {
        // Try to connect points[i] with points[j].
        dist[j] = Math.min(dist[j], Math.abs(points[i][0] - points[j][0]) +
                                        Math.abs(points[i][1] - points[j][1]));
        // Swap points[j] (point with min dist) with points[i + 1].
        if (dist[j] < dist[i + 1]) {
          final int[] tempPoint = points[j];
          points[j] = points[i + 1];
          points[i + 1] = tempPoint;
          final int tempDist = dist[j];
          dist[j] = dist[i + 1];
          dist[i + 1] = tempDist;
        }
      }
      ans += dist[i + 1];
    }

    return ans;
  }
}
