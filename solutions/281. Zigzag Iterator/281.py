class ZigzagIterator:
  def __init__(self, v1: list[int], v2: list[int]):
    def vals():
      for i in itertools.count():
        for v in v1, v2:
          if i < len(v):
            yield v[i]
    self.vals = vals()
    self.n = len(v1) + len(v2)

  def next(self):
    self.n -= 1
    return next(self.vals)

  def hasNext(self):
    return self.n > 0
