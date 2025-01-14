class Solution:
  def maxHappyGroups(self, batchSize: int, groups: list[int]) -> int:
    happy = 0
    freq = [0] * batchSize

    for g in groups:
      g %= batchSize
      if g == 0:
        happy += 1
      elif freq[batchSize - g]:
        freq[batchSize - g] -= 1
        happy += 1
      else:
        freq[g] += 1

    @functools.lru_cache(None)
    def dp(freq: int, remainder: int) -> int:
      """Returns the maximum number of partitions can be formed."""
      ans = 0
      if any(freq):
        for i, f in enumerate(freq):
          if f:
            ans = max(ans, dp(freq[:i] + (f - 1,) +
                              freq[i + 1:], (remainder + i) % batchSize))
        if remainder == 0:
          ans += 1
      return ans

    return happy + dp(tuple(freq), 0)
