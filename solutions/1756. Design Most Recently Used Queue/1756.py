from sortedcontainers import SortedList


class MRUQueue:
  def __init__(self, n: int):
    # [(priority value, actual value)]
    self.q = SortedList((i, i) for i in range(1, n + 1))

  def fetch(self, k: int) -> int:
    _, num = self.q.pop(k - 1)
    if self.q:
      maxPriority = self.q[-1][0]
      self.q.add((maxPriority + 1, num))
    else:
      self.q.add((0, num))
    return num
