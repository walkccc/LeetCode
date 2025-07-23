class Solution {
  public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
    final int maxMask = 1 << n;
    final int[][] dist = floydWarshall(n, edges);
    int[] ans = new int[n - 1];

    // mask := the subset of the cities
    for (int mask = 0; mask < maxMask; ++mask) {
      int maxDist = getMaxDist(mask, dist, n);
      if (maxDist > 0)
        ++ans[maxDist - 1];
    }

    return ans;
  }

  private int[][] floydWarshall(int n, int[][] edges) {
    int[][] dist = new int[n][n];
    for (int i = 0; i < n; ++i)
      Arrays.fill(dist[i], n);

    for (int i = 0; i < n; ++i)
      dist[i][i] = 0;

    for (int[] edge : edges) {
      final int u = edge[0] - 1;
      final int v = edge[1] - 1;
      dist[u][v] = 1;
      dist[v][u] = 1;
    }

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
  }

  private int getMaxDist(int mask, int[][] dist, int n) {
    int maxDist = 0;
    int edgeCount = 0;
    int cityCount = 0;
    for (int u = 0; u < n; ++u) {
      if ((mask >> u & 1) == 0) // u is not in the subset.
        continue;
      ++cityCount;
      for (int v = u + 1; v < n; ++v) {
        if ((mask >> v & 1) == 0) // v is not in the subset.
          continue;
        if (dist[u][v] == 1) // u and v are connected.
          ++edgeCount;
        maxDist = Math.max(maxDist, dist[u][v]);
      }
    }
    return edgeCount == cityCount - 1 ? maxDist : 0;
  }
}
