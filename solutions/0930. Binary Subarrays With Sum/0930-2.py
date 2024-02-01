class Solution:
  def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
    def numSubarraysWithSumAtMost(goal: int) -> int:
      res = 0
      count = 0
      l = 0
      r = 0

      while r < len(nums):
        count += nums[r]
        r += 1
        while l < r and count > goal:
          count -= nums[l]
          l += 1
        # nums[l..r), nums[l + 1..r), ..., nums[r - 1]
        res += r - l

      return res

    return numSubarraysWithSumAtMost(goal) - numSubarraysWithSumAtMost(goal - 1)
