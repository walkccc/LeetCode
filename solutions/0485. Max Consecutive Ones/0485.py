class Solution:
  def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
    ans = 0
    sum = 0

    for num in nums:
      if num == 0:
        sum = 0
      else:
        sum += num
        ans = max(ans, sum)

    return ans
