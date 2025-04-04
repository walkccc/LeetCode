class Solution:
  # Similar to 2104. Sum of Subarray Ranges
  def minMaxSubarraySum(self, nums: list[int], k: int) -> int:
    prevGt, nextGt = self._getPrevNext(nums, operator.lt)
    prevLt, nextLt = self._getPrevNext(nums, operator.gt)
    return (self._subarraySum(nums, prevGt, nextGt, k) +
            self._subarraySum(nums, prevLt, nextLt, k))

  def _subarraySum(
      self,
      nums: list[int],
      prev: list[int],
      next: list[int],
      k: int
  ) -> int:
    """
    Returns the sum of all subarrays with a size <= k, The `prev` and `next`
    arrays are used to store the indices of the nearest numbers that are
    smaller or larger than the current number, respectively.
    """
    res = 0
    for i, num in enumerate(nums):
      l = min(i - prev[i], k)
      r = min(next[i] - i, k)
      extra = max(0, l + r - 1 - k)
      res += num * (l * r - extra * (extra + 1) // 2)
    return res

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
        index = stack.pop()
        next[index] = i
      if stack:
        prev[i] = stack[-1]
      stack.append(i)
    return prev, next
