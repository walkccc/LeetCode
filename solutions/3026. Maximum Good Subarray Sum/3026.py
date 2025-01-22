class Solution:
  def maximumSubarraySum(self, nums: list[int], k: int) -> int:
    ans = -math.inf
    prefix = 0
    numToMinPrefix = {}

    for num in nums:
      if num not in numToMinPrefix or numToMinPrefix[num] > prefix:
        numToMinPrefix[num] = prefix
      prefix += num
      if num + k in numToMinPrefix:
        ans = max(ans, prefix - numToMinPrefix[num + k])
      if num - k in numToMinPrefix:
        ans = max(ans, prefix - numToMinPrefix[num - k])

    return 0 if ans == -math.inf else ans
