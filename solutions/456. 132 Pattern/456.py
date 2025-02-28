class Solution:
  def find132pattern(self, nums: list[int]) -> bool:
    stack = []  # a decreasing stack
    ak = -math.inf  # Find a seq, where ai < ak < aj.

    for num in reversed(nums):
      # If ai < ak, done because ai must < aj.
      if num < ak:
        return True
      while stack and stack[-1] < num:
        ak = stack[-1]
        stack.pop()
      stack.append(num)  # `nums[i]` is a candidate of aj.

    return False
