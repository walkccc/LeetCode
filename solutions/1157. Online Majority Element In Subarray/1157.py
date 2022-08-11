class MajorityChecker:
  def __init__(self, arr: List[int]):
    self.A = arr
    self.kTimes = 20  # 2^kTimes >> len(A)
    self.numToIndices = defaultdict(list)

    for i, a in enumerate(self.A):
      self.numToIndices[a].append(i)

  def query(self, left: int, right: int, threshold: int) -> int:
    for _ in range(self.kTimes):
      randIndex = randint(0, len(self.A) - 1)
      num = self.A[randIndex]
      indices = self.numToIndices[num]
      l = bisect.bisect_left(indices, left)
      r = bisect.bisect_right(indices, right)
      if r - l >= threshold:
        return num

    return -1
