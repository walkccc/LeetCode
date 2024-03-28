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
  def friendRequests(self, n: int, restrictions: List[List[int]], requests: List[List[int]]) -> List[bool]:
    ans = []
    uf = UnionFind(n)

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
        uf.unionByRank(pu, pv)

    return ans
