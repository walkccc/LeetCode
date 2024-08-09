class DetectSquares:
  def __init__(self):
    self.pointCount = collections.Counter()

  def add(self, point: List[int]) -> None:
    self.pointCount[tuple(point)] += 1

  def count(self, point: List[int]) -> int:
    x1, y1 = point
    ans = 0
    for (x3, y3), c in self.pointCount.items():
      if x1 != x3 and abs(x1 - x3) == abs(y1 - y3):
        ans += c * self.pointCount[(x1, y3)] * self.pointCount[(x3, y1)]
    return ans
