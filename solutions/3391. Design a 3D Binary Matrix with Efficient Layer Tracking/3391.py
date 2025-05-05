class Matrix3D:
  def __init__(self, n: int):
    self.isSet = set()
    # count[x] := the number of set cells in the x-th layer
    self.count = collections.Counter()
    # (count[x], x)
    self.pairs: SortedList = SortedList(key=lambda x: (-x[0], -x[1]))
    self.pairs.update((0, x) for x in range(n))

  def setCell(self, x: int, y: int, z: int) -> None:
    if (x, y, z) in self.isSet:
      return
    self.isSet.add((x, y, z))
    self.pairs.remove((self.count[x], x))
    self.count[x] += 1
    self.pairs.add((self.count[x], x))

  def unsetCell(self, x: int, y: int, z: int) -> None:
    if (x, y, z) not in self.isSet:
      return
    self.isSet.remove((x, y, z))
    self.pairs.remove((self.count[x], x))
    self.count[x] -= 1
    self.pairs.add((self.count[x], x))

  def largestMatrix(self) -> int:
    return self.pairs[0][1]
