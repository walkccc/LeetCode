class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n
    self.nodeCount = [1] * n
    self.edgeCount = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    self.edgeCount[i] += 1
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
      self.edgeCount[j] += self.edgeCount[i]
      self.nodeCount[j] += self.nodeCount[i]
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
      self.edgeCount[i] += self.edgeCount[j]
      self.nodeCount[i] += self.nodeCount[j]
    else:
      self.id[i] = j
      self.edgeCount[j] += self.edgeCount[i]
      self.nodeCount[j] += self.nodeCount[i]
      self.rank[j] += 1

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]

  def isComplete(self, u):
    return self.nodeCount[u] * (self.nodeCount[u] - 1) // 2 == self.edgeCount[u]


class Solution:
  def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
    ans = 0
    uf = UnionFind(n)
    parents = set()

    for u, v in edges:
      uf.unionByRank(u, v)

    for i in range(n):
      parent = uf.find(i)
      if parent not in parents and uf.isComplete(parent):
        ans += 1
        parents.add(parent)

    return ans
