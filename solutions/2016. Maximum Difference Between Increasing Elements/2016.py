class Solution:
  def maximumDifference(self, nums: list[int]) -> int:
    ans = -1
    mn = nums[0]

    for i in range(len(nums)):
      if nums[i] > mn:
        ans = max(ans, nums[i] - mn)
      mn = min(mn, nums[i])

    return ans
