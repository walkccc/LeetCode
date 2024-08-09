class Solution:
  def minOperations(self, nums: List[int], x: int) -> int:
    targetSum = sum(nums) - x
    if targetSum == 0:
      return len(nums)
    maxLen = self._maxSubArrayLen(nums, targetSum)
    return -1 if maxLen == -1 else len(nums) - maxLen

  # Same as 325. Maximum Size Subarray Sum Equals k
  def _maxSubArrayLen(self, nums: List[int], k: int) -> int:
    res = -1
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += num
      target = prefix - k
      if target in prefixToIndex:
        res = max(res, i - prefixToIndex[target])
      # No need to check the existence of the prefix since it's unique.
      prefixToIndex[prefix] = i

    return res
