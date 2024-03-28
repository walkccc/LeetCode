class Solution:
  def nextGreaterElements(self, nums: List[int]) -> List[int]:
    n = len(nums)
    ans = [-1] * n
    stack = []  # a decreasing stack storing indices

    for i in range(n * 2):
      num = nums[i % n]
      while stack and nums[stack[-1]] < num:
        ans[stack.pop()] = num
      if i < n:
        stack.append(i)

    return ans
