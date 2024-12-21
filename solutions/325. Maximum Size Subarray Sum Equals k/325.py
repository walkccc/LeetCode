class Solution:
  def maxSubArrayLen(self, nums: list[int], k: int) -> int:
    ans = 0
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += num
      target = prefix - k
      if target in prefixToIndex:
        ans = max(ans, i - prefixToIndex[target])
      if prefix not in prefixToIndex:
        prefixToIndex[prefix] = i

    return ans
