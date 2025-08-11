class NumArray:
  def __init__(self, nums: list[int]):
    self.prefix = list(itertools.accumulate(nums, initial=0))

  def sumRange(self, left: int, right: int) -> int:
    return self.prefix[right + 1] - self.prefix[left]
