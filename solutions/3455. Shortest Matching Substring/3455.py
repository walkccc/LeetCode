class Solution:
  def shortestMatchingSubstring(self, s: str, p: str) -> int:
    n = len(s)
    a, b, c = p.split('*')
    lpsA = self._getLPS(a + '#' + s)[len(a) + 1:]
    lpsB = self._getLPS(b + '#' + s)[len(b) + 1:]
    lpsC = self._getLPS(c + '#' + s)[len(c) + 1:]
    ans = math.inf

    i = 0  # lpsA's index
    j = 0  # lpsB's index
    k = 0  # lpsC's index
    while i + len(b) + len(c) < n:
      while i < n and lpsA[i] != len(a):
        i += 1
      while j < n and (j < i + len(b) or lpsB[j] != len(b)):
        j += 1
      while k < n and (k < j + len(c) or lpsC[k] != len(c)):
        k += 1
      if k == n:
        break
      ans = min(ans, k - i + len(a))
      i += 1

    return -1 if ans == math.inf else ans

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
