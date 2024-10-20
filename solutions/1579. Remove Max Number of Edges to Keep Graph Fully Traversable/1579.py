class UnionFind:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> bool:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return False
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1
    self.count -= 1
    return True

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def maxNumEdgesToRemove(self, n: int, edges: list[list[int]]) -> int:
    alice = UnionFind(n)
    bob = UnionFind(n)
    requiredEdges = 0

    # Greedily put type 3 edges in the front.
    for type_, u, v in sorted(edges, reverse=True):
      u -= 1
      v -= 1
      if type_ == 3:  # Can be traversed by Alice and Bob.
          # Note that we should use | instead of or because if the first
          # expression is True, short-circuiting will skip the second
          # expression.
        if alice.unionByRank(u, v) | bob.unionByRank(u, v):
          requiredEdges += 1
      elif type_ == 2:  # Can be traversed by Bob.
        if bob.unionByRank(u, v):
          requiredEdges += 1
      else:  # type == 1 Can be traversed by Alice.
        if alice.unionByRank(u, v):
          requiredEdges += 1

    return (len(edges) - requiredEdges
            if alice.count == 1 and bob.count == 1
            else -1)
