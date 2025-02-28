class Solution:
  def maximumLengthOfRanges(self, nums: list[int]) -> list[int]:
    ans = [0] * len(nums)
    stack = []  # a decreasing stack

    for i in range(len(nums) + 1):
      while stack and (i == len(nums) or nums[stack[-1]] < nums[i]):
        index = stack.pop()
        left = stack[-1] if stack else -1
        ans[index] = i - left - 1
      stack.append(i)

    return ans
