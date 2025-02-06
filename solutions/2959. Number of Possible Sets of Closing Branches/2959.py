class Solution:
  def numberOfSets(
      self,
      n: int,
      maxDistance: int,
      roads: list[list[int]],
  ) -> int:
    return sum(self._floydWarshall(n, maxDistance, roads, mask) <= maxDistance
               for mask in range(1 << n))

  def _floydWarshall(
      self,
      n: int,
      maxDistanceThreshold: int,
      roads: list[list[int]],
      mask: int,
  ) -> list[list[int]]:
    """
    Returns the maximum distance between any two branches, where the mask
    represents the selected branches.
    """
    maxDistance = 0
    dist = [[maxDistanceThreshold + 1] * n for _ in range(n)]

    for i in range(n):
      if mask >> i & 1:
        dist[i][i] = 0

    for u, v, w in roads:
      if mask >> u & 1 and mask >> v & 1:
        dist[u][v] = min(dist[u][v], w)
        dist[v][u] = min(dist[v][u], w)

    for k in range(n):
      if mask >> k & 1:
        for i in range(n):
          if mask >> i & 1:
            for j in range(n):
              if mask >> j & 1:
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for i in range(n):
      if mask >> i & 1:
        for j in range(i + 1, n):
          if mask >> j & 1:
            maxDistance = max(maxDistance, dist[i][j])

    return maxDistance
