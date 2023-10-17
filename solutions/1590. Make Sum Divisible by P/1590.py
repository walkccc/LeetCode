class Solution:
  def minSubarray(self, nums: List[int], p: int) -> int:
    summ = sum(nums)
    remainder = summ % p
    if remainder == 0:
      return 0

    ans = len(nums)
    prefix = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefix += num
      prefix %= p
      target = (prefix - remainder + p) % p
      if target in prefixToIndex:
        ans = min(ans, i - prefixToIndex[target])
      prefixToIndex[prefix] = i

    return -1 if ans == len(nums) else ans
