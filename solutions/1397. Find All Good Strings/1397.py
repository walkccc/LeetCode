class Solution:
  def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
    kMod = 1_000_000_007
    evilLPS = self._getLPS(evil)

    # NextMatchedCount(i, j) := # Next matched evil count given that there're
    # Already i matches with `evil` and the current is ('a' + j)
    # J := the next index we're trying to match with `currChar`
    @functools.lru_cache(None)
    def getNextMatchedEvilCount(j: int, currChar: str) -> int:
      while j > 0 and evil[j] != currChar:
        j = evilLPS[j - 1]
      return j + 1 if evil[j] == currChar else j

    # dp(i, j, k1, k2) := # of good strings for s[i:] and there're already j
    # Matches with `evil`, where k1 is the 0//1 tight constraint for s1 and k2
    # Is the 0//1 tight constraint for s2
    @functools.lru_cache(None)
    def dp(i: int, matchedEvilCount: int, isS1Prefix: bool, isS2Prefix: bool) -> int:
      # s[:i] contains `evil`, so don't consider any ongoing strings
      if matchedEvilCount == len(evil):
        return 0
      # Run out of string, contributes one
      if i == n:
        return 1
      ans = 0
      minCharIndex = ord(s1[i]) if isS1Prefix else ord('a')
      maxCharIndex = ord(s2[i]) if isS2Prefix else ord('z')
      for charIndex in range(minCharIndex, maxCharIndex + 1):
        c = chr(charIndex)
        nextMatchedEvilCount = getNextMatchedEvilCount(matchedEvilCount, c)
        ans += dp(i + 1, nextMatchedEvilCount,
                  isS1Prefix and c == s1[i],
                  isS2Prefix and c == s2[i])
        ans %= kMod
      return ans

    return dp(0, 0, True, True)

  # Get Longest Prefix also Suffix
  def _getLPS(self, s: str) -> List[int]:
    lps = [0] * len(s)
    j = 0
    for i in range(1, len(s)):
      while j > 0 and s[j] != s[i]:
        j = lps[j - 1]
      if s[i] == s[j]:
        lps[i] = j + 1
        j += 1
    return lps
