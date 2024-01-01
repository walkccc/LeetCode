class Solution:
  def equalDigitFrequency(self, s: str) -> int:
    power = 11
    kMod = 1_000_000_007
    seen = set()

    def isUnique(s: str, i: int, j: int) -> bool:
      count = [0] * 10
      unique = 0
      for k in range(i, j + 1):
        count[ord(s[k]) - ord('0')] += 1
        if count[ord(s[k]) - ord('0')] == 1:
          unique += 1
      maxCount = max(count)
      return maxCount * unique == j - i + 1

    def getRollingHash(s: str, i: int, j: int) -> int:
      hash = 0
      for k in range(i, j + 1):
        hash = (hash * power + val(s[k])) % kMod
      return hash

    def val(c: str) -> int:
      return ord(c) - ord('0') + 1

    for i in range(len(s)):
      for j in range(i, len(s)):
        if isUnique(s, i, j):
          seen.add(getRollingHash(s, i, j))

    return len(seen)
