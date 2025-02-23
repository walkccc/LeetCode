class Solution {
 public:
  int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    const int maxMask = 1 << n;
    int ans = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      if (floydWarshall(n, maxDistance, roads, mask) <= maxDistance)
        ++ans;

    return ans;
  }

 private:
  // Returns the maximum distance between any two branches, where the mask
  // represents the selected branches.
  int floydWarshall(int n, int maxDistanceThreshold, vector<vector<int>>& roads,
                    int mask) {
    int maxDistance = 0;
    vector<vector<int>> dist(n, vector<int>(n, maxDistanceThreshold + 1));

    for (int i = 0; i < n; ++i)
      if (mask >> i & 1)
        dist[i][i] = 0;

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      const int w = road[2];
      if (mask >> u & 1 && mask >> v & 1) {
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
      }
    }

    for (int k = 0; k < n; ++k)
      if (mask >> k & 1)
        for (int i = 0; i < n; ++i)
          if (mask >> i & 1)
            for (int j = 0; j < n; ++j)
              if (mask >> j & 1)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < n; ++i)
      if (mask >> i & 1)
        for (int j = i + 1; j < n; ++j)
          if (mask >> j & 1)
            maxDistance = max(maxDistance, dist[i][j]);

    return maxDistance;
  }
};
