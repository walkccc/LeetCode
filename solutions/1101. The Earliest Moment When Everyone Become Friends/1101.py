class UnionFind:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1
    self.count -= 1

  def getCount(self) -> int:
    return self.count

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def earliestAcq(self, logs: list[list[int]], n: int) -> int:
    uf = UnionFind(n)

    # Sort `logs` by timestamp.
    logs.sort(key=lambda x: x[0])

    for timestamp, x, y in logs:
      uf.unionByRank(x, y)
      if uf.getCount() == 1:
        return timestamp

    return -1
