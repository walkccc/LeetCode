class Solution:
  def minStartingIndex(self, s: str, pattern: str) -> int:
    z1 = self._zFunction(pattern + s)
    z2 = self._zFunction(pattern[::-1] + s[::-1])

    # Match s[i..i + len(pattern) - 1] with `pattern` from both the prefix and
    # the suffix.
    for i in range(len(s) - len(pattern) + 1):
      if z1[len(pattern) + i] + z2[len(s) - i] >= len(pattern) - 1:
        return i

    return -1

  def _zFunction(self, s: str) -> list[int]:
    """
    Returns the z array, where z[i] is the length of the longest prefix of
    s[i..n) which is also a prefix of s.

    https://cp-algorithms.com/string/z-function.html#implementation
    """
    n = len(s)
    z = [0] * n
    l = 0
    r = 0
    for i in range(1, n):
      if i < r:
        z[i] = min(r - i, z[i - l])
      while i + z[i] < n and s[z[i]] == s[i + z[i]]:
        z[i] += 1
      if i + z[i] > r:
        l = i
        r = i + z[i]
    return z
