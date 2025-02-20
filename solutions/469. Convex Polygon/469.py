class Solution:
  def isConvex(self, points: list[list[int]]) -> bool:
    def getCross(p: list[int], q: list[int], r: list[int]):
      """Returns pq x qr."""
      return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0])

    sign = 0
    for i in range(len(points)):
      cross = getCross(points[i - 2], points[i - 1], points[i])
      if cross == 0:  # p, q, r are collinear.
        continue
      if sign == 0:  # Find the first cross that's not 0.
        sign = cross
      elif cross * sign < 0:
        return False

    return True
