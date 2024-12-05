class Solution:
  def countWinningSequences(self, s: str) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, prev: int, bob: int) -> int:
      """
      Returns the number of distinct sequences Bob can use to beat Alice for
      s[i..n), where the previous character is `prev` (0: F, 1: W, 2: E) and the
      number of points that Bob is having is `bob`.
      """
      if i == len(s):
        return int(bob > 0)

      f = 0  # If Bob summons a Fire Dragon at i.
      w = 0  # If Bob summons a Water Serpent at i.
      e = 0  # If Bob summons a Earth Golem at i.

      match s[i]:
        case 'F':
          if prev != 0:
            f = dp(i + 1, 0, bob) % kMod
          if prev != 1:
            w = dp(i + 1, 1, bob + 1) % kMod
          if prev != 2:
            e = dp(i + 1, 2, bob - 1) % kMod
        case 'W':
          if prev != 0:
            f = dp(i + 1, 0, bob - 1) % kMod
          if prev != 1:
            w = dp(i + 1, 1, bob) % kMod
          if prev != 2:
            e = dp(i + 1, 2, bob + 1) % kMod
        case 'E':
          if prev != 0:
            f = dp(i + 1, 0, bob + 1) % kMod
          if prev != 1:
            w = dp(i + 1, 1, bob - 1) % kMod
          if prev != 2:
            e = dp(i + 1, 2, bob) % kMod

      return f + w + e

    return (dp(0, 0, 0) + dp(0, 1, 0) + dp(0, 2, 0)) // 2 % kMod
