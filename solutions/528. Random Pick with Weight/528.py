class Solution:
  def __init__(self, w: list[int]):
    self.prefix = list(itertools.accumulate(w))

  def pickIndex(self) -> int:
    target = random.randint(0, self.prefix[-1] - 1)
    return bisect.bisect_right(range(len(self.prefix)), target,
                               key=lambda m: self.prefix[m])
