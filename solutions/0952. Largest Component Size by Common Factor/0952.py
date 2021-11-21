class UF:
  def __init__(self, n: int):
    self.parent = [i for i in range(n + 1)]

  def union(self, u: int, v: int) -> bool:
    pu = self.find(u)
    pv = self.find(v)
    if pu == pv:
      return False
    self.parent[pu] = pv
    return True

  def find(self, u: int) -> int:
    if self.parent[u] != u:
      self.parent[u] = self.find(self.parent[u])
    return self.parent[u]


class Solution:
  def largestComponentSize(self, A: List[int]) -> int:
    ans = 0
    uf = UF(max(A))
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
