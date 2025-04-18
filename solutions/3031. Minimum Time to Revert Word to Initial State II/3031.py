class Solution:
  # Same as 3029. Minimum Time to Revert Word to Initial State I
  def minimumTimeToInitialState(self, word: str, k: int) -> int:
    n = len(word)
    maxOps = (n - 1) // k + 1
    z = self._zFunction(word)

    for ans in range(1, maxOps):
      if z[ans * k] >= n - ans * k:
        return ans

    return maxOps

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
