class Solution:
  def maxCoins(self, nums: List[int]) -> int:
    A = [1] + nums + [1]

    @lru_cache(None)
    def dp(i, j):
      if i > j:
        return 0

      return max(dp(i, k - 1) + dp(k + 1, j) + A[i - 1] * A[k] * A[j + 1]
                 for k in range(i, j + 1))

    return dp(1, len(nums))
