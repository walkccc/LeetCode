class NumArray:
  def __init__(self, nums: List[int]):
    self.prefix = [0] + list(itertools.accumulate(nums))

  def sumRange(self, left: int, right: int) -> int:
    return self.prefix[right + 1] - self.prefix[left]
