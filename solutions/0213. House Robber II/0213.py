class Solution:
  def rob(self, nums: List[int]) -> int:
    if not nums:
      return 0
    if len(nums) < 2:
      return nums[0]

    def rob(l: int, r: int) -> int:
      dp1 = 0
      dp2 = 0

      for i in range(l, r + 1):
        temp = dp1
        dp1 = max(dp1, dp2 + nums[i])
        dp2 = temp

      return dp1

    return max(rob(0, len(nums) - 2),
               rob(1, len(nums) - 1))
