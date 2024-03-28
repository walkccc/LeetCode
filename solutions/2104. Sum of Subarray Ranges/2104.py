class Solution:
  def subArrayRanges(self, nums: List[int]) -> int:
    n = len(nums)

    def sumSubarray(A: List[int], op):
      ans = 0
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
        ans += a * (i - prev[i]) * (next[i] - i)

      return ans

    return sumSubarray(nums, operator.lt) - sumSubarray(nums, operator.gt)
