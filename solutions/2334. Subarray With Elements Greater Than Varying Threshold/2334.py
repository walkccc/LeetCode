class Solution:
  # very similar to 907. Sum of Subarray Minimums
  def validSubarraySize(self, nums: List[int], threshold: int) -> int:
    n = len(nums)
    ans = 0
    # prev[i] := index k s.t. nums[k] is the prev min in nums[:i]
    prev = [-1] * n
    # next[i] := index k s.t. nums[k] is the next min in nums[i + 1:]
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
