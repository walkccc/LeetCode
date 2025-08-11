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
  def resultArray(self, nums: list[int]) -> list[int]:
    arr1 = []
    arr2 = []
    ranks = self._getRanks(nums)
    tree1 = FenwickTree(len(ranks))
    tree2 = FenwickTree(len(ranks))

    def add(num: int, arr: list[int], tree: FenwickTree) -> None:
      arr.append(num)
      tree.add(ranks[num], 1)

    add(nums[0], arr1, tree1)
    add(nums[1], arr2, tree2)

    for i in range(2, len(nums)):
      greaterCount1 = len(arr1) - tree1.get(ranks[nums[i]])
      greaterCount2 = len(arr2) - tree2.get(ranks[nums[i]])
      if greaterCount1 > greaterCount2:
        add(nums[i], arr1, tree1)
      elif greaterCount1 < greaterCount2:
        add(nums[i], arr2, tree2)
      elif len(arr1) > len(arr2):
        add(nums[i], arr2, tree2)
      else:
        add(nums[i], arr1, tree1)

    return arr1 + arr2

  def _getRanks(self, nums: list[int]) -> dict[int, int]:
    ranks = collections.Counter()
    rank = 0
    for num in sorted(set(nums)):
      rank += 1
      ranks[num] = rank
    return ranks
