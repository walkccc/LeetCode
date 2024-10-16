class Solution:
  def minIncrementOperations(self, nums: list[int], k: int) -> int:
    # the minimum operations to increase nums[i - 3] and nums[0..i - 3)
    prev3 = 0
    # the minimum operations to increase nums[i - 2] and nums[0..i - 2)
    prev2 = 0
    # the minimum operations to increase nums[i - 1] and nums[0..i - 1)
    prev1 = 0

    for num in nums:
      dp = min(prev1, prev2, prev3) + max(0, k - num)
      prev3 = prev2
      prev2 = prev1
      prev1 = dp

    return min(prev1, prev2, prev3)
