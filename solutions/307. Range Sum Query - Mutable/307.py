class FenwickTree:
  def __init__(self, n: int):
    self.sums = [0] * (n + 1)

  def update(self, i: int, delta: int) -> None:
    while i < len(self.sums):
      self.sums[i] += delta
      i += FenwickTree.lowbit(i)

  def get(self, i: int) -> int:
    summ = 0
    while i > 0:
      summ += self.sums[i]
      i -= FenwickTree.lowbit(i)
    return summ

  @staticmethod
  def lowbit(i: int) -> int:
    return i & -i


class NumArray:
  def __init__(self, nums: List[int]):
    self.nums = nums
    self.tree = FenwickTree(len(nums))
    for i, num in enumerate(nums):
      self.tree.update(i + 1, num)

  def update(self, index: int, val: int) -> None:
    self.tree.update(index + 1, val - self.nums[index])
    self.nums[index] = val

  def sumRange(self, left: int, right: int) -> int:
    return self.tree.get(right + 1) - self.tree.get(left)
