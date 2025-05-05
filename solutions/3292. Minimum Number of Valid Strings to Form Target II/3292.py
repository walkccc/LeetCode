class Solution:
  # 3291. Minimum Number of Valid Strings to Form Target I
  def minValidStrings(self, words: list[str], target: str) -> int:
    ans = 0
    unmatchedPrefix = len(target)
    lpsList = [self._getLPS(word + '#' + target) for word in words]

    while unmatchedPrefix > 0:
      # Greedily choose the word that has the longest suffix match with the
      # remaining unmatched prefix.
      maxMatchSuffix = 0
      for lps, word in zip(lpsList, words):
        maxMatchSuffix = max(maxMatchSuffix, lps[len(word) + unmatchedPrefix])
      if maxMatchSuffix == 0:
        return -1
      ans += 1
      unmatchedPrefix -= maxMatchSuffix

    return ans

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
