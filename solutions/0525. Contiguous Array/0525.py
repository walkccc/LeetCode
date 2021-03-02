class Solution:
  def findMaxLength(self, nums: List[int]) -> int:
    ans = 0
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += 1 if num else -1
      if prefix in prefixToIndex:
        ans = max(ans, i - prefixToIndex[prefix])
      else:
        prefixToIndex[prefix] = i

    return ans
