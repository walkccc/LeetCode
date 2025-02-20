import statistics


class Solution:
  def minMoves2(self, nums: list[int]) -> int:
    median = int(statistics.median(nums))
    return sum(abs(num - median) for num in nums)
