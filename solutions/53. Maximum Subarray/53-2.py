class Solution:
  def maxSubArray(self, nums: list[int]) -> int:
    ans = -math.inf
    summ = 0

    for num in nums:
      summ = max(num, summ + num)
      ans = max(ans, summ)

    return ans
