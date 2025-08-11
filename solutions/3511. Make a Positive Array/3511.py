class Solution:
  def makeArrayPositive(self, nums: list[int]) -> int:
    MAX = 10**18
    ans = 0
    minSum = nums[0] + nums[1]

    for i in range(2, len(nums)):
      a, b, c = nums[i - 2], nums[i - 1], nums[i]
      minSum = min(minSum + c, a + b + c)
      if minSum <= 0:
        nums[i] = MAX
        minSum = MAX
        ans += 1

    return ans
