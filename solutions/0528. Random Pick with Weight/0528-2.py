class Solution:
  def __init__(self, w: List[int]):
    self.prefix = list(itertools.accumulate(w))

  def pickIndex(self) -> int:
    return bisect_left(self.prefix, random.random() * self.prefix[-1])
