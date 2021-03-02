class Solution:
  def largestComponentSize(self, A: List[int]) -> int:
    n = max(A)

    ans = 0
    uf = UF(n)
    count = Counter()

    for a in A:
      for num in range(2, int(sqrt(a) + 1)):
        if a % num == 0:
          uf.union(a, num)
          uf.union(a, a // num)

    for a in A:
      pa = uf.find(a)
      count[pa] += 1
      ans = max(ans, count[pa])

    return ans


class UF:
  def __init__(self, n: int):
    self.rank = [0] * (n + 1)
    self.parent = [i for i in range(n + 1)]

  def union(self, u: int, v: int) -> None:
    pu = self.parent[u]
    pv = self.parent[v]
    if pu == pv:
      return

    if self.rank[pu] < self.rank[pv]:
      self.parent[pu] = pv
    elif self.rank[pv] < self.rank[pu]:
      self.parent[pv] = pu
    else:
      self.parent[pu] = pv
      self.rank[pv] += 1

  def find(self, u: int) -> int:
    while u != self.parent[u]:
      self.parent[u] = self.parent[self.parent[u]]
      u = self.parent[u]

    return u
