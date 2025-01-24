class Solution:
  # Similar to 3349. Adjacent Increasing Subarrays Detection I
  def maxIncreasingSubarrays(self, nums: list[int]) -> int:
    ans = 0
    increasing = 1
    prevIncreasing = 0

    for a, b in itertools.pairwise(nums):
      if b > a:
        increasing += 1
      else:
        prevIncreasing = increasing
        increasing = 1
      ans = max(ans, increasing // 2)
      ans = max(ans, min(prevIncreasing, increasing))

    return ans
