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
  def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
    ans = ''
    uf = UnionFind(len(s))
    map = collections.defaultdict(list)

    for a, b in pairs:
      uf.unionByRank(a, b)

    for i, c in enumerate(s):
      map[uf.find(i)].append(c)

    for key in map.keys():
      map[key].sort(reverse=True)

    for i in range(len(s)):
      ans += map[uf.find(i)].pop()

    return ans
