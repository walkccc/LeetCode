class Solution:
  def similarPairs(self, words: list[str]) -> int:
    masks = [self._getMask(word) for word in words]
    return sum(masks[i] == masks[j]
               for i, j in itertools.combinations(range(len(masks)), 2))

  def _getMask(self, word: str) -> int:
    mask = 0
    for c in word:
      mask |= 1 << ord(c) - ord('a')
    return mask
