class FenwichTree:
  def __init__(self, n: int):
    self.n = n
    self.sums = [0] * (2 * n + 1)

  def add(self, i: int, delta: int) -> None:
    i += self.n + 1  # re-mapping
    while i < len(self.sums):
      self.sums[i] += delta
      i += i & -i

  def get(self, i: int) -> int:
    i += self.n + 1  # re-mapping
    summ = 0
    while i > 0:
      summ += self.sums[i]
      i -= i & -i
    return summ


class Solution:
  def subarraysWithMoreZerosThanOnes(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    ans = 0
    prefix = 0
    tree = FenwichTree(len(nums))
    tree.add(0, 1)

    for num in nums:
      prefix += -1 if num == 0 else 1
      ans += tree.get(prefix - 1)
      ans %= kMod
      tree.add(prefix, 1)

    return ans
