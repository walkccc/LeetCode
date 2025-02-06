class Solution:
  def maximumSum(self, nums: list[int]) -> int:
    ans = 0

    for oddPower in range(1, len(nums) + 1):
      summ = 0
      for num in range(1, len(nums) + 1):
        if num * num * oddPower > len(nums):
          break
        summ += nums[oddPower * num * num - 1]
      ans = max(ans, summ)

    return ans
