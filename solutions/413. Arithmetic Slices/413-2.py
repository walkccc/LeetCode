class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:
    ans = 0
    dp = 0

    for i in range(2, len(nums)):
      if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
        dp += 1
        ans += dp
      else:
        dp = 0

    return ans
