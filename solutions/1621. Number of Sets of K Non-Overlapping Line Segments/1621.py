class Solution:
  def numberOfSets(self, n: int, k: int) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, k: int, drawing: bool) -> int:
      if k == 0:  # Find a way to draw k segments.
        return 1
      if i == n:  # Reach the end.
        return 0
      if drawing:
        # 1. Keep drawing at i and move to i + 1.
        # 2. Stop at i so decrease k. We can start from i for the next segment.
        return (dp(i + 1, k, True) + dp(i, k - 1, False)) % kMod
      # 1. Skip i and move to i + 1.
      # 2. Start at i and move to i + 1.
      return (dp(i + 1, k, False) + dp(i + 1, k, True)) % kMod

    return dp(0, k, False)
