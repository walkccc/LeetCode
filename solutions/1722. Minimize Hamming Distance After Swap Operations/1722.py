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
  def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
    n = len(source)
    ans = 0
    uf = UnionFind(n)
    groupIdToCount = [collections.Counter() for _ in range(n)]

    for a, b in allowedSwaps:
      uf.unionByRank(a, b)

    for i in range(n):
      groupIdToCount[uf.find(i)][source[i]] += 1

    for i in range(n):
      groupId = uf.find(i)
      count = groupIdToCount[groupId]
      if target[i] not in count:
        ans += 1
      else:
        count[target[i]] -= 1
        if count[target[i]] == 0:
          del count[target[i]]

    return ans
