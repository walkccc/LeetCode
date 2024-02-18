class Solution:
  def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
    kMax = 10000
    dist1 = self._getDist(edges, node1)
    dist2 = self._getDist(edges, node2)
    minDist = kMax
    ans = -1

    for i, (d1, d2) in enumerate(zip(dist1, dist2)):
      if min(d1, d2) >= 0:
        maxDist = max(d1, d2)
        if maxDist < minDist:
          minDist = maxDist
          ans = i

    return ans

  def _getDist(self, edges: List[int], u: int) -> List[int]:
    dist = [-1] * len(edges)
    d = 0
    while u != -1 and dist[u] == -1:
      dist[u] = d
      d += 1
      u = edges[u]
    return dist
