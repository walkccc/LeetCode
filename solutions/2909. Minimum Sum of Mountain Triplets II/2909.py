class Solution:
  # Same as 2908. Minimum Sum of Mountain Triplets I
  def minimumSum(self, nums: list[int]) -> int:
    ans = math.inf
    minPrefix = list(itertools.accumulate(nums, min))
    minSuffix = list(itertools.accumulate(reversed(nums), min))[::-1]

    for i, num in enumerate(nums):
      if num > minPrefix[i] and num > minSuffix[i]:
        ans = min(ans, num + minPrefix[i] + minSuffix[i])

    return -1 if ans == math.inf else ans
