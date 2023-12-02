class Solution:
  def minSizeSubarray(self, nums: List[int], target: int) -> int:
    summ = sum(nums)
    n = len(nums)
    remainingTarget = target % summ
    repeatLength = (target // summ) * n
    if remainingTarget == 0:
      return repeatLength

    suffixPlusPrefixLength = n
    prefix = 0
    prefixToIndex = {0: -1}

    for i in range(2 * n):
      prefix += nums[i % n]
      if prefix - remainingTarget in prefixToIndex:
        suffixPlusPrefixLength = min(
            suffixPlusPrefixLength,
            i - prefixToIndex[prefix - remainingTarget])
      prefixToIndex[prefix] = i

    return -1 if suffixPlusPrefixLength == n else suffixPlusPrefixLength + repeatLength
