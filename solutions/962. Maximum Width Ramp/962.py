class Solution:
  def maxWidthRamp(self, nums: list[int]) -> int:
    ans = 0
    stack = []

    for i, num in enumerate(nums):
      if stack == [] or num <= nums[stack[-1]]:
        stack.append(i)

    for i, num in reversed(list(enumerate(nums))):
      while stack and num >= nums[stack[-1]]:
        ans = max(ans, i - stack.pop())

    return ans
