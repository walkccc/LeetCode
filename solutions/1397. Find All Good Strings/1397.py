class Solution:
  def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
    kMod = 1_000_000_007
    evilLPS = self._getLPS(evil)

    @functools.lru_cache(None)
    def getNextMatchedEvilCount(j: int, currChar: str) -> int:
      """
      Returns the number of next matched evil count, where there're j matches
      with `evil` and the current letter is ('a' + j).
      """
      while j > 0 and evil[j] != currChar:
        j = evilLPS[j - 1]
      return j + 1 if evil[j] == currChar else j

    @functools.lru_cache(None)
    def dp(i: int, matchedEvilCount: int, isS1Prefix: bool, isS2Prefix: bool) -> int:
      """
      Returns the number of good strings for s[i..n), where there're j matches
      with `evil`, `isS1Prefix` indicates if the current letter is tightly bound
      for `s1` and `isS2Prefix` indicates if the current letter is tightly bound
      for `s2`.
      """
      # s[0..i) contains `evil`, so don't consider any ongoing strings.
      if matchedEvilCount == len(evil):
        return 0
      # Run out of strings, so contribute one.
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

  def _getLPS(self, pattern: str) -> list[int]:
    """
    Returns the lps array, where lps[i] is the length of the longest prefix of
    pattern[0..i] which is also a suffix of this substring.
    """
    lps = [0] * len(pattern)
    j = 0
    for i in range(1, len(pattern)):
      while j > 0 and pattern[j] != pattern[i]:
        j = lps[j - 1]
      if pattern[i] == pattern[j]:
        lps[i] = j + 1
        j += 1
    return lps
