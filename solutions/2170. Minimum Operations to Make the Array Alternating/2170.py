class T:
  def __init__(self):
    self.count = collections.Counter()
    self.mx = 0
    self.secondMax = 0
    self.maxFreq = 0
    self.secondMaxFreq = 0


class Solution:
  def minimumOperations(self, nums: list[int]) -> int:
    # 0 := odd indices, 1 := even indices
    ts = [T() for _ in range(2)]

    for i, num in enumerate(nums):
      t = ts[i % 2]
      t.count[num] += 1
      freq = t.count[num]
      if freq > t.maxFreq:
        t.maxFreq = freq
        t.mx = num
      elif freq > t.secondMaxFreq:
        t.secondMaxFreq = freq
        t.secondMax = num

    if ts[0].mx == ts[1].mx:
      return len(nums) - max(ts[0].maxFreq + ts[1].secondMaxFreq,
                             ts[1].maxFreq + ts[0].secondMaxFreq)
    return len(nums) - (ts[0].maxFreq + ts[1].maxFreq)
