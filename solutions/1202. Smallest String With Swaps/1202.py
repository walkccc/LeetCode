class Solution:
  def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
    class UF:
      def __init__(self, n: int):
        self.size = [1] * n
        self.id = list(range(n))

      def union(self, p: int, q: int) -> None:
        i = self.find(p)
        j = self.find(q)
        if i == j:
          return
        if self.size[i] < self.size[j]:
          self.id[i] = j
          self.size[j] += self.size[i]
        else:
          self.id[j] = i
          self.size[i] += self.size[j]

      def find(self, i: int) -> int:
        while i != self.id[i]:
          self.id[i] = self.id[self.id[i]]
          i = self.id[i]
        return i

    ans = ""
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
