class Solution:
  def numberOfSubarrays(self, nums: list[int]) -> int:
    ans = 0
    stack = []

    for num in nums:
      while stack and stack[-1][0] < num:
        stack.pop()
      if not stack or stack[-1][0] != num:
        stack.append([num, 0])
      stack[-1][1] += 1
      ans += stack[-1][1]

    return ans
