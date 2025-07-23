class Solution:
  def minMaxWeight(self, n: int, edges: list[list[int]], threshold: int) -> int:
    MAX = 1000000
    reversedGraph = [[] for _ in range(n)]

    for u, v, w in edges:
      reversedGraph[v].append((u, w))

    l = 1
    r = MAX + 1

    while l < r:
      m = (l + r) // 2
      if self._dfs(reversedGraph, 0, m, set()) == n:
        r = m
      else:
        l = m + 1

    return -1 if l == MAX + 1 else l

  def _dfs(
      self,
      reversedGraph: list[list[tuple]],
      u: int,
      maxWeight: int,
      seen: set[int]
  ) -> int:
    """Returns the number of nodes reachable from u with weight <= maxWeight."""
    res = 1
    seen.add(u)
    for v, w in reversedGraph[u]:
      if w > maxWeight or v in seen:
        continue
      res += self._dfs(reversedGraph, v, maxWeight, seen)
    return res
