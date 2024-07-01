class MajorityChecker:
  def __init__(self, arr: List[int]):
    self.arr = arr
    self.kTimes = 20  # 2^kTimes >> |arr|
    self.numToIndices = collections.defaultdict(list)

    for i, a in enumerate(self.arr):
      self.numToIndices[a].append(i)

  def query(self, left: int, right: int, threshold: int) -> int:
    for _ in range(self.kTimes):
      randIndex = random.randint(left, right)
      num = self.arr[randIndex]
      indices = self.numToIndices[num]
      l = bisect.bisect_left(indices, left)
      r = bisect.bisect_right(indices, right)
      if r - l >= threshold:
        return num

    return -1
