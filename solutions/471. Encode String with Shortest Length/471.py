class Solution:
  def encode(self, s: str) -> str:
    n = len(s)

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> str:
      """Returns the shortest encoded string of s[i..j]."""
      curr = s[i:j + 1]
      res = curr

      if len(res) < 5:
        return res

      # Try all possible partitions.
      for k in range(i, j):
        l = dp(i, k)
        r = dp(k + 1, j)
        if len(l) + len(r) < len(res):
          res = l + r

      # Try to compress the string.
      # e.g. s = aabaabaab -> 3[aab]
      for k in range(i, j):
        pattern = s[i:k + 1]
        if len(curr) % len(pattern) == 0 and pattern * (len(curr) //
                                                        len(pattern)) == curr:
          candidate = f"{len(curr) // len(pattern)}[{dp(i, k)}]"
          if len(candidate) < len(res):
            res = candidate

      return res

    return dp(0, n - 1)
