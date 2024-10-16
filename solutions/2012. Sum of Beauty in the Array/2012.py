class Solution:
  def sumOfBeauties(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0
    minOfRight = [0] * (n - 1) + [nums[-1]]

    for i in range(n - 2, 1, -1):
      minOfRight[i] = min(nums[i], minOfRight[i + 1])

    maxOfLeft = nums[0]

    for i in range(1, n - 1):
      if maxOfLeft < nums[i] < minOfRight[i + 1]:
        ans += 2
      elif nums[i - 1] < nums[i] < nums[i + 1]:
        ans += 1
      maxOfLeft = max(maxOfLeft, nums[i])

    return ans
