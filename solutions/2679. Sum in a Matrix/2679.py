class Solution:
  def matrixSum(self, nums: list[list[int]]) -> int:
    for row in nums:
      row.sort()

    return sum(max(col) for col in zip(*nums))
