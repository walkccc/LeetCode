class UF:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.size = [1] * n
    self.rank = [0] * n

  def union(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = self.id[j]
      self.size[j] += self.size[i]
    elif self.rank[j] < self.rank[i]:
      self.id[j] = self.id[i]
      self.size[i] += self.size[j]
    else:
      self.id[i] = self.id[j]
      self.size[j] += self.size[i]
      self.rank[j] += 1
    self.count -= 1

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def groupStrings(self, words: List[str]) -> List[int]:
    uf = UF(len(words))

    def getMask(s: str) -> int:
      mask = 0
      for c in s:
        mask |= 1 << ord(c) - ord('a')
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
          uf.union(i, maskToIndex[m])
      for m in getDeletedMasks(mask):
        if m in maskToIndex:
          uf.union(i, maskToIndex[m])
        if m in deletedMaskToIndex:
          uf.union(i, deletedMaskToIndex[m])
        else:
          deletedMaskToIndex[m] = i

    return [uf.count, max(uf.size)]
