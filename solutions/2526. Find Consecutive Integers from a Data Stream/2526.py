class DataStream:
  def __init__(self, value: int, k: int):
    self.value = value
    self.k = k
    self.q = deque()
    self.count = 0

  def consec(self, num: int) -> bool:
    if len(self.q) == self.k and self.q.popleft() == self.value:
      self.count -= 1
    if num == self.value:
      self.count += 1
    self.q.append(num)
    return self.count == self.k
