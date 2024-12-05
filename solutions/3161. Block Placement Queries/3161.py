from sortedcontainers import SortedList


class FenwickTree:
  def __init__(self, n: int):
    self.vals = [0] * (n + 1)

  def maximize(self, i: int, val: int) -> None:
    while i < len(self.vals):
      self.vals[i] = max(self.vals[i], val)
      i += FenwickTree.lowtree(i)

  def get(self, i: int) -> int:
    res = 0
    while i > 0:
      res = max(res, self.vals[i])
      i -= FenwickTree.lowtree(i)
    return res

  @staticmethod
  def lowtree(i: int) -> int:
    return i & -i


class Solution:
  def getResults(self, queries: list[list[int]]) -> list[bool]:
    n = min(50000, len(queries) * 3)
    ans = []
    tree = FenwickTree(n + 1)
    obstacles = SortedList([0, n])  # sentinel values

    for query in queries:
      type = query[0]
      if type == 1:
        x = query[1]
        obstacles.add(x)

    for x1, x2 in itertools.pairwise(obstacles):
      tree.maximize(x2, x2 - x1)

    for query in reversed(queries):
      type = query[0]
      x = query[1]
      if type == 1:
        i = obstacles.index(x)
        next = obstacles[i + 1]
        prev = obstacles[i - 1]
        obstacles.remove(x)
        tree.maximize(next, next - prev)
      else:
        sz = query[2]
        i = obstacles.bisect_right(x)
        prev = obstacles[i - 1]
        ans.append(tree.get(prev) >= sz or x - prev >= sz)

    return ans[::-1]
