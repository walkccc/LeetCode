class Solution:
  def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
    def helper(l: int, r: int) -> int:
      n = len(nums)
      left = [0] * n
      sum = 0

      for i in range(n):
        sum += nums[i]
        if i >= l:
          sum -= nums[i - l]
        if i >= l - 1:
          left[i] = max(left[i - 1], sum) if i > 0 else sum

      right = [0] * n
      sum = 0

      for i in reversed(range(n)):
        sum += nums[i]
        if i <= n - r - 1:
          sum -= nums[i + r]
        if i <= n - r:
          right[i] = max(right[i + 1], sum) if i < n - 1 else sum

      return max(left[i] + right[i + 1] for i in range(n - 1))

    return max(helper(firstLen, secondLen), helper(secondLen, firstLen))
