class Solution:
  def maxRemovals(
      self,
      source: str,
      pattern: str,
      targetIndices: list[int]
  ) -> int:
    m = len(source)
    n = len(pattern)
    target = set(targetIndices)

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """
      Returns the maximum number of operations that can be performed for
      source[i..m) and pattern[j..n).
      """
      if i == m:
        return 0 if j == n else -math.inf
      if j == n:
        return int(i in target) + dp(i + 1, j)
      pick = dp(i + 1, j + 1) if source[i] == pattern[j] else -math.inf
      skip = int(i in target) + dp(i + 1, j)
      return max(pick, skip)

    ans = dp(0, 0)
    return 0 if ans == -math.inf else ans
