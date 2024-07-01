class Vector2D:
  def __init__(self, vec: List[List[int]]):
    self.vec = []
    self.i = 0

    for A in vec:
      self.vec += A

  def next(self) -> int:
    ans = self.vec[self.i]
    self.i += 1
    return ans

  def hasNext(self) -> bool:
    return self.i < len(self.vec)
