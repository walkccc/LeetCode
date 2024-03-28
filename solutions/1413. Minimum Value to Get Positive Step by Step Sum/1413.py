class Solution:
  def minStartValue(self, nums: List[int]) -> int:
    summ = 0
    minSum = 0

    for num in nums:
      summ += num
      minSum = min(minSum, summ)

    return 1 - minSum
