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
  def processQueries(self, queries: list[int], m: int) -> list[int]:
    ans = []
    # Map [-m, m] to [0, 2 * m].
    tree = FenwickTree(2 * m + 1)
    numToIndex = {num: num + m for num in range(1, m + 1)}

    for num in range(1, m + 1):
      tree.add(num + m, 1)

    nextEmptyIndex = m  # Map 0 to m.

    for query in queries:
      index = numToIndex[query]
      ans.append(tree.get(index - 1))
      # Move `query` from `index` to `nextEmptyIndex`.
      tree.add(index, -1)
      tree.add(nextEmptyIndex, 1)
      numToIndex[query] = nextEmptyIndex
      nextEmptyIndex -= 1

    return ans
