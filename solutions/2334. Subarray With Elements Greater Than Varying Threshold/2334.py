class Solution:
  # Similar to 907. Sum of Subarray Minimums
  def validSubarraySize(self, nums: List[int], threshold: int) -> int:
    n = len(nums)
    ans = 0
    # prev[i] := the index k s.t. nums[k] is the previous minimum in nums[0..n)
    prev = [-1] * n
    # next[i] := the index k s.t. nums[k] is the next minimum in nums[i + 1..n)
    next = [n] * n
    stack = []

    for i, a in enumerate(nums):
      while stack and nums[stack[-1]] > a:
        index = stack.pop()
        next[index] = i
      if stack:
        prev[i] = stack[-1]
      stack.append(i)

    for i, (num, prevIndex, nextIndex) in enumerate(zip(nums, prev, next)):
      k = (i - prevIndex) + (nextIndex - i) - 1
      if num > threshold / k:
        return k

    return -1
