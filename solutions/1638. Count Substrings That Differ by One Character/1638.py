class Solution:
  def countSubstrings(self, s: str, t: str) -> int:
    ans = 0

    for i in range(len(s)):
      ans += self._count(s, t, i, 0)

    for j in range(1, len(t)):
      ans += self._count(s, t, 0, j)

    return ans

  def _count(self, s: str, t: str, i: int, j: int) -> int:
    """Returns the number of substrings of s[i..n) and t[j:] that differ by one char."""
    res = 0
    # the number of substrings starting at s[i] and t[j] ending in the current
    # index with zero different letter
    dp0 = 0
    # the number of substrings starting at s[i] and t[j] ending in the current
    # index with one different letter
    dp1 = 0

    while i < len(s) and j < len(t):
      if s[i] == t[j]:
        dp0 += 1
      else:
        dp0, dp1 = 0, dp0 + 1
      res += dp1
      i += 1
      j += 1

    return res
