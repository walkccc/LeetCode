class Solution:
  def __init__(self, rects: List[List[int]]):
    self.rects = rects
    self.areas = list(itertools.accumulate(
        [(x2 - x1 + 1) * (y2 - y1 + 1) for x1, y1, x2, y2 in rects]))

  def pick(self) -> List[int]:
    index = bisect_right(self.areas, randint(0, self.areas[-1] - 1))
    x1, y1, x2, y2 = self.rects[index]
    return [randint(x1, x2), randint(y1, y2)]
