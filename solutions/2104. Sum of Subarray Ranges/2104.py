class Solution:
  def subArrayRanges(self, nums: list[int]) -> int:
    n = len(nums)

    def sumSubarray(A: list[int], op):
      res = 0
      prev = [-1] * n
      next = [n] * n
      stack = []

      for i, a in enumerate(A):
        while stack and op(A[stack[-1]], a):
          index = stack.pop()
          next[index] = i
        if stack:
          prev[i] = stack[-1]
        stack.append(i)

      for i, a in enumerate(A):
        res += a * (i - prev[i]) * (next[i] - i)

      return res

    return sumSubarray(nums, operator.lt) - sumSubarray(nums, operator.gt)
