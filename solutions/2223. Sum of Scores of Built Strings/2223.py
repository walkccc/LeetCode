class Solution:
  def sumScores(self, s: str) -> int:
    n = len(s)
    # https://cp-algorithms.com/string/z-function.html#implementation
    z = [0] * n
    # [l, r] := the indices of the rightmost segment match
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

    return sum(z) + n
