class Solution:
  # Same as 3006. Find Beautiful Indices in the Given Array I
  def beautifulIndices(self, s: str, a: str, b: str, k: int) -> list[int]:
    ans = []
    indicesA = self._kmp(s, a)
    indicesB = self._kmp(s, b)
    indicesBIndex = 0  # indicesB' index

    for i in indicesA:
      # The constraint is: |j - i| <= k. So, -k <= j - i <= k. So, move
      # `indicesBIndex` s.t. j - i >= -k, where j := indicesB[indicesBIndex].
      while indicesBIndex < len(indicesB) and indicesB[indicesBIndex] - i < -k:
        indicesBIndex += 1
      if indicesBIndex < len(indicesB) and indicesB[indicesBIndex] - i <= k:
        ans.append(i)

    return ans

  def _kmp(self, s: str, pattern: str) -> list[int]:
    """Returns the starting indices of all occurrences of the pattern in `s`."""

    def getLPS(pattern: str) -> list[int]:
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

    lps = getLPS(pattern)
    res = []
    i = 0  # s' index
    j = 0  # pattern's index
    while i < len(s):
      if s[i] == pattern[j]:
        i += 1
        j += 1
        if j == len(pattern):
          res.append(i - j)
          j = lps[j - 1]
      # Mismatch after j matches.
      elif j != 0:
          # Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1]
      else:
        i += 1
    return res
