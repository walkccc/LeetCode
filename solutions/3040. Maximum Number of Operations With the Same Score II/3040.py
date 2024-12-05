class Solution:
  def maxOperations(self, nums: list[int]) -> int:
    @functools.lru_cache(None)
    def dp(i: int, j: int, score: int) -> int:
      """
      Returns the maximum number of operations that can be performed for
      nums[i..j], s.t. all operations have the same `score`.
      """
      if i >= j:
        return 0
      deleteFirstTwo = (1 + dp(i + 2, j, score)
                        if nums[i] + nums[i + 1] == score else 0)
      deleteLastTwo = (1 + dp(i, j - 2, score)
                       if nums[j] + nums[j - 1] == score else 0)
      deleteFirstAndLast = (1 + dp(i + 1, j - 1, score)
                            if nums[i] + nums[j] == score else 0)
      return max(deleteFirstTwo, deleteLastTwo, deleteFirstAndLast)

    n = len(nums)
    return max(dp(0, n - 1, nums[0] + nums[1]),
               dp(0, n - 1, nums[-1] + nums[-2]),
               dp(0, n - 1, nums[0] + nums[-1]))
