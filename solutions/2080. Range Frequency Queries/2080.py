class RangeFreqQuery:
  def __init__(self, arr: List[int]):
    self.valueToIndices = collections.defaultdict(list)
    for i, a in enumerate(arr):
      self.valueToIndices[a].append(i)

  def query(self, left: int, right: int, value: int) -> int:
    indices = self.valueToIndices[value]
    i = bisect_left(indices, left)
    j = bisect_right(indices, right)
    return j - i
