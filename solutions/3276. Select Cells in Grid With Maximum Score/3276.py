class Solution:
  def maxScore(self, grid: list[list[int]]) -> int:
    numToIndices = collections.defaultdict(set)
    for index, row in enumerate(grid):
      for num in row:
        numToIndices[num].add(index)
    numToIndices = list(numToIndices.items())

    @functools.lru_cache(None)
    def dp(i: int, mask: int) -> int:
      """
      Returns the maximum score by selecting numbers from numToIndices[i..],
      where `mask` is the bitmask of the used row indices.
      """
      if i == len(numToIndices):
        return 0
      # Skip numToIndices[i][0].
      res = dp(i + 1, mask)
      for index in numToIndices[i][1]:
        if (mask >> index & 1) == 0:
          # Take numToIndices[i][0].
          res = max(res, numToIndices[i][0] + dp(i + 1, mask | 1 << index))
      return res

    return dp(0, 0)
