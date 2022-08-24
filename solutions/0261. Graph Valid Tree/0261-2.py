class UF:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))

  def union(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return
    self.id[i] = j
    self.count -= 1

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def validTree(self, n: int, edges: List[List[int]]) -> bool:
    if n == 0 or len(edges) != n - 1:
      return False

    uf = UF(n)

    for u, v in edges:
      uf.union(u, v)

    return uf.count == 1
