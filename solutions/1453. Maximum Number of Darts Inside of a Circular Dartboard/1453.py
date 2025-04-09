class Point:
  def __init__(self, x: float, y: float):
    self.x = x
    self.y = y


class Solution:
  def numPoints(self, darts: list[list[int]], r: int) -> int:
    ERR = 1e-6
    ans = 1
    points = [Point(x, y) for x, y in darts]

    def dist(p: Point, q: Point) -> float:
      return ((p.x - q.x)**2 + (p.y - q.y)**2)**0.5

    def getCircles(p: Point, q: Point) -> list[Point]:
      if dist(p, q) - 2.0 * r > ERR:
        return []
      m = Point((p.x + q.x) / 2, (p.y + q.y) / 2)
      distCM = (r**2 - (dist(p, q) / 2)**2)**0.5
      alpha = math.atan2(p.y - q.y, q.x - p.x)
      return [Point(m.x - distCM * math.sin(alpha), m.y - distCM * math.cos(alpha)),
              Point(m.x + distCM * math.sin(alpha), m.y + distCM * math.cos(alpha))]

    for i, j in itertools.combinations(points, 2):
      for c in getCircles(i, j):
        count = 0
        for point in points:
          if dist(c, point) - r <= ERR:
            count += 1
        ans = max(ans, count)

    return ans
