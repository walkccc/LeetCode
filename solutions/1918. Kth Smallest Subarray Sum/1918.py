class Solution:
  def kthSmallestSubarraySum(self, nums: List[int], k: int) -> int:
    def numSubarrayLessThan(m: int) -> int:
      res = 0
      summ = 0
      l = 0
      for r, num in enumerate(nums):
        summ += num
        while summ > m:
          summ -= nums[l]
          l += 1
        res += r - l + 1
      return res

    return bisect.bisect_left(range(0, sum(nums)), k,
                              key=lambda m: numSubarrayLessThan(m))
