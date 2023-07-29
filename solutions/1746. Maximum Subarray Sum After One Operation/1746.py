class Solution:
  def maxSumAfterOperation(self, nums: List[int]) -> int:
    ans = -math.inf
    regular = 0
    squared = 0

    for num in nums:
      squared = max(num**2, regular + num**2, squared + num)
      regular = max(num, regular + num)
      ans = max(ans, squared)

    return ans
