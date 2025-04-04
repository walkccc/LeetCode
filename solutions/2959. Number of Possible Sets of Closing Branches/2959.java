class Solution {
  public int numberOfSets(int n, int maxDistance, int[][] roads) {
    final int maxMask = 1 << n;
    int ans = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      if (floydWarshall(n, maxDistance, roads, mask) <= maxDistance)
        ++ans;

    return ans;
  }

  private int floydWarshall(int n, int maxDistanceThreshold, int[][] roads, int mask) {
    int maxDistance = 0;
    int[][] dist = new int[n][n];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, maxDistanceThreshold + 1));

    for (int i = 0; i < n; ++i)
      if ((mask >> i & 1) == 1)
        dist[i][i] = 0;

    for (int[] road : roads) {
      final int u = road[0];
      final int v = road[1];
      final int w = road[2];
      if ((mask >> u & 1) == 1 && (mask >> v & 1) == 1) {
        dist[u][v] = Math.min(dist[u][v], w);
        dist[v][u] = Math.min(dist[v][u], w);
      }
    }

    for (int k = 0; k < n; ++k)
      if ((mask >> k & 1) == 1)
        for (int i = 0; i < n; ++i)
          if ((mask >> i & 1) == 1)
            for (int j = 0; j < n; ++j)
              if ((mask >> j & 1) == 1)
                dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < n; ++i)
      if ((mask >> i & 1) == 1)
        for (int j = i + 1; j < n; ++j)
          if ((mask >> j & 1) == 1)
            maxDistance = Math.max(maxDistance, dist[i][j]);

    return maxDistance;
  }
}
