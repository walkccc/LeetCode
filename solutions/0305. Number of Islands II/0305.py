class UnionFind:
  def __init__(self, n: int):
    self.id = [-1] * n
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
  def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
    dirs = [0, 1, 0, -1, 0]
    ans = []
    seen = [[False] * n for _ in range(m)]
    uf = UnionFind(m * n)
    count = 0

    def getId(i: int, j: int, n: int) -> int:
      return i * n + j

    for i, j in positions:
      if seen[i][j]:
        ans.append(count)
        continue
      seen[i][j] = True
      id = getId(i, j, n)
      uf.id[id] = id
      count += 1
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        neighborId = getId(x, y, n)
        if uf.id[neighborId] == -1:  # water
          continue
        currentParent = uf.find(id)
        neighborParent = uf.find(neighborId)
        if currentParent != neighborParent:
          uf.unionByRank(currentParent, neighborParent)
          count -= 1
      ans.append(count)

    return ans
