class FenwickTree:
  def __init__(self, n: int):
    self.sums = [0] * (n + 1)

  def add(self, i: int, delta: int) -> None:
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


class Solution:
  def countOfPeaks(
      self,
      nums: list[int],
      queries:
      list[list[int]],
  ) -> list[int]:
    ans = []
    peak = [0] + [int(a < b > c)
                  for a, b, c in zip(nums[:-2], nums[1:-1], nums[2:])] + [0]
    tree = FenwickTree(len(peak))

    for i, p in enumerate(peak):
      tree.add(i + 1, p)

    def update(i: int) -> None:
      """
      Update the peak array and Fenwick tree if the peak status of nums[i]
      changes.
      """
      newPeak = self._isPeak(nums, i)
      if newPeak != peak[i]:
        tree.add(i + 1, newPeak - peak[i])
        peak[i] = newPeak

    for query in queries:
      if query[0] == 1:
        l = query[1]
        r = query[2]
        ans.append(0 if r - l < 2 else tree.get(r) - tree.get(l + 1))
      elif query[0] == 2:
        index = query[1]
        val = query[2]
        nums[index] = val
        update(index)
        if index > 0:
          update(index - 1)
        if index + 1 < len(nums):
          update(index + 1)

    return ans

  def _isPeak(self, nums: list[int], i: int) -> bool:
    return i > 0 and i + 1 < len(nums) and nums[i - 1] < nums[i] > nums[i + 1]
