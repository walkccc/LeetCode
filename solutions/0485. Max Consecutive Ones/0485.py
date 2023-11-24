class Solution:
  def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
    ans = 0
    summ = 0

    for num in nums:
      if num == 0:
        summ = 0
      else:
        summ += num
        ans = max(ans, summ)

    return ans
