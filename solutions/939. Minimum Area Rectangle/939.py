class Solution:
  def minAreaRect(self, points: List[List[int]]) -> int:
    ans = math.inf
    xToYs = collections.defaultdict(set)

    for x, y in points:
      xToYs[x].add(y)

    for i in range(len(points)):
      for j in range(i):
        x1, y1 = points[i]
        x2, y2 = points[j]
        if x1 == x2 or y1 == y2:
          continue
        if y2 in xToYs[x1] and y1 in xToYs[x2]:
          ans = min(ans, abs(x1 - x2) * abs(y1 - y2))

    return ans if ans < math.inf else 0
