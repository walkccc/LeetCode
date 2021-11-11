class UF:
  def __init__(self, n: int):
    self.size = n
    self.parent = [i for i in range(n)]

  def union(self, u: int, v: int) -> None:
    pu = self.find(u)
    pv = self.find(v)
    if pu == pv:
      return

    self.parent[pu] = pv
    self.size -= 1

  def find(self, u: int) -> int:
    if u != self.parent[u]:
      self.parent[u] = self.find(self.parent[u])
    return self.parent[u]


class Solution:
  def findCircleNum(self, M: List[List[int]]) -> int:
    n = len(M)

    uf = UF(n)

    for i in range(n):
      for j in range(i, n):
        if M[i][j] == 1:
          uf.union(i, j)

    return uf.size
