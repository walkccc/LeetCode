class Solution:
  def similarPairs(self, words: list[str]) -> int:
    ans = 0

    def getMask(word: str) -> int:
      mask = 0
      for c in word:
        mask |= 1 << string.ascii_lowercase.index(c)
      return mask

    masks = [getMask(word) for word in words]

    for i in range(len(masks)):
      for j in range(i + 1, len(masks)):
        if masks[i] == masks[j]:
          ans += 1

    return ans
