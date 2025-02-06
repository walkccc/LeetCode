class Solution:
  def findMaxLength(self, nums: list[int]) -> int:
    ans = 0
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += 1 if num else -1
      ans = max(ans, i - prefixToIndex.setdefault(prefix, i))

    return ans
