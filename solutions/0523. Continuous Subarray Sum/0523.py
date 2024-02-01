class Solution:
  def checkSubarraySum(self, nums: List[int], k: int) -> bool:
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += num
      if k != 0:
        prefix %= k
      if prefix in prefixToIndex:
        if i - prefixToIndex[prefix] > 1:
          return True
      else:
        # Set a new key if it's absent because the previous index is better.
        prefixToIndex[prefix] = i

    return False
