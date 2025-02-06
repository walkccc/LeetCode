class Solution:
  def maxSubarrayLength(self, nums: list[int]) -> int:
    ans = 0
    stack = []

    for i in range(len(nums) - 1, -1, -1):
      # If nums[stack[-1]] <= nums[i], stack[-1] is better than i.
      # So, no need to append it.
      if not stack or nums[stack[-1]] > nums[i]:
        stack.append(i)

    for i, num in enumerate(nums):
      while stack and num > nums[stack[-1]]:
        ans = max(ans, stack.pop() - i + 1)

    return ans
