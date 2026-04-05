class Solution:
  def minOperations(self, nums: list[int]) -> int:
    ans = 0
    stack = [0]

    for num in nums:
      while stack and stack[-1] > num:
        stack.pop()
      if not stack or stack[-1] < num:
        ans += 1
        stack.append(num)

    return ans
