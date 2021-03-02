class Solution:
  def nextGreaterElements(self, nums: List[int]) -> List[int]:
    ans = [-1] * len(nums)
    stack = []

    for i in range(len(nums) * 2):
      num = nums[i % len(nums)]
      while stack and nums[stack[-1]] < num:
        ans[stack.pop()] = num
      if i < len(nums):
        stack.append(i)

    return ans
