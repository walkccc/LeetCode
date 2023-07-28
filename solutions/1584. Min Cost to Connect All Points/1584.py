class Solution:
  def minCostConnectPoints(self, points: List[int]) -> int:
    # dist[i] := min distance to connect points[i]
    dist = [math.inf] * len(points)
    ans = 0

    for i in range(len(points) - 1):
      for j in range(i + 1, len(points)):
        # Try to connect points[i] with points[j].
        dist[j] = min(dist[j], abs(points[i][0] - points[j][0]) +
                      abs(points[i][1] - points[j][1]))
        # Swap points[j] (point with min dist) with points[i + 1].
        if dist[j] < dist[i + 1]:
          points[j], points[i + 1] = points[i + 1], points[j]
          dist[j], dist[i + 1] = dist[i + 1], dist[j]
      ans += dist[i + 1]

    return ans
