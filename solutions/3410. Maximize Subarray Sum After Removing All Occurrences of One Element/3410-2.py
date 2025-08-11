class Solution:
  def maxSubarraySum(self, nums: list[int]) -> int:
    ans = max(nums)
    prefix = 0
    minPrefix = 0
    # the minimum prefix sum that can have a negative number removed
    modifiedMinPrefix = 0
    count = collections.Counter()
    # minPrefixPlusRemoval[num] := the minimum prefix sum plus removed `num`
    minPrefixPlusRemoval = {}

    for num in nums:
      prefix += num
      ans = max(ans, prefix - modifiedMinPrefix)
      if num < 0:
        count[num] += 1
        minPrefixPlusRemoval[num] = (
            min(minPrefixPlusRemoval.get(num, 0), minPrefix) + num)
        modifiedMinPrefix = min(modifiedMinPrefix,
                                count[num] * num,
                                minPrefixPlusRemoval[num])
      minPrefix = min(minPrefix, prefix)
      modifiedMinPrefix = min(modifiedMinPrefix, minPrefix)

    return ans
