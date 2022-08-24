class UF:
  def __init__(self, n: int):
    self.id = list(range(n))

  def union(self, u: int, v: int) -> None:
    self.id[self.find(u)] = self.find(v)

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
    ans = ''
    uf = UF(len(s))
    map = defaultdict(list)

    for p, q in pairs:
      uf.union(p, q)

    for i in range(len(s)):
      map[uf.find(i)].append(s[i])

    for key in map.keys():
      map[key].sort(reverse=True)

    for i in range(len(s)):
      ans += map[uf.find(i)].pop()

    return ans
