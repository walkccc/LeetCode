class Solution:
  def isRectangleCover(self, rectangles: list[list[int]]) -> bool:
    area = 0
    x1 = math.inf
    y1 = math.inf
    x2 = -math.inf
    y2 = -math.inf
    corners: set[tuple[int, int]] = set()

    for x, y, a, b in rectangles:
      area += (a - x) * (b - y)
      x1 = min(x1, x)
      y1 = min(y1, y)
      x2 = max(x2, a)
      y2 = max(y2, b)

      # the four points of the current rectangle
      for point in [(x, y), (x, b), (a, y), (a, b)]:
        if point in corners:
          corners.remove(point)
        else:
          corners.add(point)

    if len(corners) != 4:
      return False
    if ((x1, y1) not in corners or
        (x1, y2) not in corners or
        (x2, y1) not in corners or
            (x2, y2) not in corners):
      return False
    return area == (x2 - x1) * (y2 - y1)
