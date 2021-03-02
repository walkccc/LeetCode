class MajorityChecker:
  def __init__(self, arr: List[int]):
    self.map = defaultdict(list)
    for i, a in enumerate(arr):
      self.map[a].append(i)

  def query(self, left: int, right: int, threshold: int) -> int:
    for num, indices in self.map.items():
      if len(indices) < threshold:
        continue
      l = bisect.bisect(indices, left - 1)
      r = bisect.bisect(indices, right)
      if r - l >= threshold:
        return num

    return -1
