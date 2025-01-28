class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def minimumCost(self, n: int, connections: list[list[int]]) -> int:
    ans = 0
    uf = UnionFind(n + 1)

    # Sort by cost.
    connections.sort(key=lambda x: x[2])

    for u, v, cost in connections:
      if uf.find(u) == uf.find(v):
        continue
      uf.unionByRank(u, v)
      ans += cost

    root = uf.find(1)
    if any(uf.find(i) != root for i in range(1, n + 1)):
      return -1

    return ans
