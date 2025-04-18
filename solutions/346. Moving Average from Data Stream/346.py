class MovingAverage:
  def __init__(self, size: int):
    self.size = size
    self.sum = 0
    self.q = collections.deque()

  def next(self, val: int) -> float:
    if len(self.q) == self.size:
      self.sum -= self.q.popleft()
    self.sum += val
    self.q.append(val)
    return self.sum / len(self.q)
