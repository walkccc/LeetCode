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
  def smallestStringWithSwaps(self, s: str, pairs: list[list[int]]) -> str:
    uf = UnionFind(len(s))
    indexToLetters = collections.defaultdict(list)

    for a, b in pairs:
      uf.unionByRank(a, b)

    for i, c in enumerate(s):
      indexToLetters[uf.find(i)].append(c)

    for key in indexToLetters.keys():
      indexToLetters[key].sort(reverse=True)

    return ''.join(indexToLetters[uf.find(i)].pop()
                   for i in range(len(s)))
