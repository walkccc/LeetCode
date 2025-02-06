class Solution:
  def wordCount(self, startWords: list[str], targetWords: list[str]) -> int:
    def getMask(s: str) -> int:
      mask = 0
      for c in s:
        mask ^= 1 << string.ascii_lowercase.index(c)
      return mask

    ans = 0
    seen = set(getMask(w) for w in startWords)

    for targetWord in targetWords:
      mask = getMask(targetWord)
      for c in targetWord:
        # Toggle one character.
        if mask ^ 1 << string.ascii_lowercase.index(c) in seen:
          ans += 1
          break

    return ans
