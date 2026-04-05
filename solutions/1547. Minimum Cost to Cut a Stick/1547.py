class Solution:
  def minCost(self, n: int, cuts: list[int]) -> int:
    A = sorted([0] + cuts + [n])

    @functools.lru_cache(None)
    def dp(i, j):
      if j - i <= 1:
        return 0

      return min(A[j] - A[i] + dp(i, k) + dp(k, j) for k in range(i + 1, j))

    return dp(0, len(A) - 1)
