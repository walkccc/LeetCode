class UF:
  def __init__(self, n: int):
    self.id = list(range(n))

  def union(self, u: int, v: int) -> None:
    self.id[u] = v

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def friendRequests(self, n: int, restrictions: List[List[int]], requests: List[List[int]]) -> List[bool]:
    ans = []
    uf = UF(n)

    for u, v in requests:
      pu = uf.find(u)
      pv = uf.find(v)
      isValid = True
      if pu != pv:
        for x, y in restrictions:
          px = uf.find(x)
          py = uf.find(y)
          if (pu, pv) in [(px, py), (py, px)]:
            isValid = False
            break
      ans.append(isValid)
      if isValid:
        uf.union(pu, pv)

    return ans
