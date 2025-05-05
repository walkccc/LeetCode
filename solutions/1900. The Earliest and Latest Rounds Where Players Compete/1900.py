class Solution:
  def earliestAndLatest(self, n: int,
                        firstPlayer: int, secondPlayer: int) -> list[int]:
    @functools.lru_cache(None)
    def dp(l: int, r: int, k: int) -> list[int]:
      """
      Returns the (earliest, latest) pair, the first player is the l-th player
      from the front, the second player is the r-th player from the end, and
      there're k people.
      """
      if l == r:
        return [1, 1]
      if l > r:
        return dp(r, l, k)

      a = math.inf
      b = -math.inf

      # Enumerate all the possible positions.
      for i in range(1, l + 1):
        for j in range(l - i + 1, r - i + 1):
          if not l + r - k // 2 <= i + j <= (k + 1) // 2:
            continue
          x, y = dp(i, j, (k + 1) // 2)
          a = min(a, x + 1)
          b = max(b, y + 1)

      return [a, b]

    return dp(firstPlayer, n - secondPlayer + 1, n)
