class Solution:
  def __init__(self, w: List[int]):
    self.prefix = list(itertools.accumulate(w))

  def pickIndex(self) -> int:
    target = randint(0, self.prefix[-1] - 1)
    l = 0
    r = len(self.prefix)

    while l < r:
      m = (l + r) // 2
      if self.prefix[m] > target:
        r = m
      else:
        l = m + 1

    return l
