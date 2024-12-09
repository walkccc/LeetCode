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
  def getPermutationIndex(self, perm: list[int]) -> int:
    kMod = 1_000_000_007
    n = len(perm)
    ans = 0
    tree = FenwickTree(n)
    fact = [1] * (n + 1)  # fact[i] := i!

    for i in range(2, n + 1):
      fact[i] = (fact[i - 1] * i) % kMod

    for i, num in enumerate(perm):
      # the number of unused numbers less than `num`
      unusedNums = num - 1 - tree.get(num - 1)
      suffixLength = fact[n - 1 - i]
      ans += unusedNums * suffixLength
      ans %= kMod
      tree.add(num, 1)

    return ans
