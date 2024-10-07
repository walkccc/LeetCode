class Solution:
  # This dynamic programming table dp[k][i] represents the number of ways to
  # rearrange the String s after k steps such that it starts with s[i].
  # A String can be rotated from 1 to n - 1 times. The transition rule is
  # dp[k][i] = sum(dp[k - 1][j]) for all j != i. For example, when n = 4 and
  # k = 3, the table looks like this:
  #
  # -----------------------------------------------------------
  # |       | i = 0 | i = 1 | i = 2 | i = 3 | sum = (n - 1)^k |
  # -----------------------------------------------------------
  # | k = 0 |   1   |   0   |   0   |   0   |        1        |
  # | k = 1 |   0   |   1   |   1   |   1   |        3        |
  # | k = 2 |   3   |   2   |   2   |   2   |        9        |
  # | k = 3 |   6   |   7   |   7   |   7   |       27        |
  # -----------------------------------------------------------
  #
  # By observation, we have
  #   * dp[k][!0] = ((n - 1)^k - (-1)^k) / n
  #   * dp[k][0] = dp[k][!0] + (-1)^k
  def numberOfWays(self, s: str, t: str, k: int) -> int:
    kMod = 1_000_000_007
    n = len(s)
    negOnePowK = 1 if k % 2 == 0 else -1  # (-1)^k
    z = self._zFunction(s + t + t)
    # indices in `s` s.t. for each `i` in the returned indices,
    # `s[i..n) + s[0..i) = t`.
    indices = [i - n for i in range(n, n + n) if z[i] >= n]
    dp = [0] * 2  # dp[0] := dp[k][0]; dp[1] := dp[k][!0]
    dp[1] = (pow(n - 1, k, kMod) - negOnePowK) * pow(n, kMod - 2, kMod)
    dp[0] = dp[1] + negOnePowK
    return sum(dp[0] if index == 0 else dp[1] for index in indices) % kMod

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
