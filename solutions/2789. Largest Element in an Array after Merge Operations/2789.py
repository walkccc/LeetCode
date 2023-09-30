class Solution:
  def maxArrayValue(self, nums: List[int]) -> int:
    ans = nums[-1]

    for i in range(len(nums) - 2, -1, -1):
      if nums[i] > ans:
        ans = nums[i]
      else:
        ans += nums[i]

    return ans
