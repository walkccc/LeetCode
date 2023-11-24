class Solution:
  def minIncrementOperations(self, nums: List[int], k: int) -> int:
    prev3 = 0  # min ops to increase nums[i - 3] and nums[:i - 3]
    prev2 = 0  # min ops to increase nums[i - 2] and nums[:i - 2]
    prev1 = 0  # min ops to increase nums[i - 1] and nums[:i - 1]

    for num in nums:
      dp = min(prev1, prev2, prev3) + max(0, k - num)
      prev3 = prev2
      prev2 = prev1
      prev1 = dp

    return min(prev1, prev2, prev3)
