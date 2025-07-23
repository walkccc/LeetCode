class Solution:
  def hasIncreasingSubarrays(self, nums: list[int], k: int) -> bool:
    increasing = 1
    prevIncreasing = 0

    for a, b in itertools.pairwise(nums):
      if b > a:
        increasing += 1
      else:
        prevIncreasing = increasing
        increasing = 1
      if increasing // 2 >= k or min(prevIncreasing, increasing) >= k:
        return True

    return False
