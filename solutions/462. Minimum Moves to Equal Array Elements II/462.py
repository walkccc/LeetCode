import statistics


class Solution:
  def minMoves2(self, nums: List[int]) -> int:
    median = int(statistics.median(nums))
    return sum(abs(num - median) for num in nums)
