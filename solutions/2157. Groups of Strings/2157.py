class UnionFind:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.sz = [1] * n

  def unionBySize(self, u: int, v: int) -> None:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return
    if self.sz[i] < self.sz[j]:
      self.sz[j] += self.sz[i]
      self.id[i] = j
    else:
      self.sz[i] += self.sz[j]
      self.id[j] = i
    self.count -= 1

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def groupStrings(self, words: list[str]) -> list[int]:
    uf = UnionFind(len(words))

    def getMask(s: str) -> int:
      mask = 0
      for c in s:
        mask |= 1 << string.ascii_lowercase.index(c)
      return mask

    def getAddedMasks(mask: int):
      for i in range(26):
        if not (mask >> i & 1):
          yield mask | 1 << i

    def getDeletedMasks(mask: int):
      for i in range(26):
        if mask >> i & 1:
          yield mask ^ 1 << i

    maskToIndex = {getMask(word): i for i, word in enumerate(words)}
    deletedMaskToIndex = {}

    for i, word in enumerate(words):
      mask = getMask(word)
      for m in getAddedMasks(mask):
        if m in maskToIndex:
          uf.unionBySize(i, maskToIndex[m])
      for m in getDeletedMasks(mask):
        if m in maskToIndex:
          uf.unionBySize(i, maskToIndex[m])
        if m in deletedMaskToIndex:
          uf.unionBySize(i, deletedMaskToIndex[m])
        else:
          deletedMaskToIndex[m] = i

    return [uf.count, max(uf.sz)]
