class Solution:
  def minimizeTheDifference(self, mat: list[list[int]], target: int) -> int:
    minSum = sum(min(row) for row in mat)
    if minSum >= target:  # No need to consider any larger combination.
      return minSum - target

    @functools.lru_cache(None)
    def dp(i: int, summ: int) -> int:
      if i == len(mat):
        return abs(summ - target)
      return min(dp(i + 1, summ + num) for num in mat[i])

    return dp(0, 0)
