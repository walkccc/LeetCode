class Solution:
  def minOperations(self, s1: str, s2: str, x: int) -> int:
    diffIndices = [i for i, (a, b) in enumerate(zip(s1, s2))
                   if a != b]
    if not diffIndices:
      return 0
    # It's impossible to make two strings equal if there are odd number of
    # differences.
    if len(diffIndices) & 1:
      return -1

    @functools.lru_cache(None)
    def dp(i: int) -> int:
      """Returns the minimum cost to correct diffIndices[i..n)."""
      if i == len(diffIndices):
        return 0
      if i == len(diffIndices) - 1:
        return x / 2
      return min(dp(i + 1) + x / 2,
                 dp(i + 2) + diffIndices[i + 1] - diffIndices[i])

    return int(dp(0))
