class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    ans = -math.inf
    summ = 0

    for num in nums:
      summ += num
      ans = max(ans, summ)
      summ = max(summ, 0)

    return ans
