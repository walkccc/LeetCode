class Solution:
  def minSpaceWastedKResizing(self, nums: list[int], k: int) -> int:
    kMax = 200_000_000

    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      """
      Returns the minimum space wasted for nums[i..n) if you can resize k times.
      """
      if i == len(nums):
        return 0
      if k == -1:
        return kMax

      res = kMax
      summ = 0
      maxNum = nums[i]

      for j in range(i, len(nums)):
        summ += nums[j]
        maxNum = max(maxNum, nums[j])
        wasted = maxNum * (j - i + 1) - summ
        res = min(res, dp(j + 1, k - 1) + wasted)

      return res

    return dp(0, k)
