class RangeModule:
  def __init__(self):
    self.A = []

  def addRange(self, left: int, right: int) -> None:
    i = bisect_left(self.A, left)
    j = bisect_right(self.A, right)
    self.A[i:j] = [left] * (i % 2 == 0) + [right] * (j % 2 == 0)

  def queryRange(self, left: int, right: int) -> bool:
    i = bisect_right(self.A, left)
    j = bisect_left(self.A, right)
    return i == j and i % 2 == 1

  def removeRange(self, left: int, right: int) -> None:
    i = bisect_left(self.A, left)
    j = bisect_right(self.A, right)
    self.A[i:j] = [left] * (i % 2 == 1) + [right] * (j % 2 == 1)
