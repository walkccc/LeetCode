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
  def countSmaller(self, nums: list[int]) -> list[int]:
    ans = []
    ranks = self._getRanks(nums)
    tree = FenwickTree(len(ranks))

    for num in reversed(nums):
      ans.append(tree.get(ranks[num] - 1))
      tree.add(ranks[num], 1)

    return ans[::-1]

  def _getRanks(self, nums: list[int]) -> dict[int, int]:
    ranks = collections.Counter()
    rank = 0
    for num in sorted(set(nums)):
      rank += 1
      ranks[num] = rank
    return ranks
