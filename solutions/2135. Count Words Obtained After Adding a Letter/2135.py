class Solution:
  def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
    def getMask(s: str) -> int:
      mask = 0
      for c in s:
        mask ^= 1 << ord(c) - ord('a')
      return mask

    ans = 0
    seen = set(getMask(w) for w in startWords)

    for targetWord in targetWords:
      mask = getMask(targetWord)
      for c in targetWord:
        # Toggle one character.
        if mask ^ 1 << ord(c) - ord('a') in seen:
          ans += 1
          break

    return ans
