class Solution:
  def subArrayRanges(self, nums: list[int]) -> int:
    prevGt, nextGt = self._getPrevNext(nums, operator.lt)
    prevLt, nextLt = self._getPrevNext(nums, operator.gt)
    return sum(num * (i - prevGt[i]) * (nextGt[i] - i) -
               num * (i - prevLt[i]) * (nextLt[i] - i)
               for i, num in enumerate(nums))

  def _getPrevNext(
      self,
      nums: list[int],
      op: callable
  ) -> tuple[list[int], list[int]]:
    """
    Returns `prev` and `next`, that store the indices of the nearest numbers
    that are smaller or larger than the current number depending on `op`.
    """
    n = len(nums)
    prev = [-1] * n
    next = [n] * n
    stack = []
    for i, num in enumerate(nums):
      while stack and op(nums[stack[-1]], num):
        next[stack.pop()] = i
      if stack:
        prev[i] = stack[-1]
      stack.append(i)
    return prev, next
