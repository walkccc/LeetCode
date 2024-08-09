class Solution:
  def maxMatrixSum(self, matrix: List[List[int]]) -> int:
    absSum = 0
    minAbs = math.inf
    # 0 := even number of negatives
    # 1 := odd number of negatives
    oddNeg = 0

    for row in matrix:
      for num in row:
        absSum += abs(num)
        minAbs = min(minAbs, abs(num))
        if num < 0:
          oddNeg ^= 1

    return absSum - oddNeg * minAbs * 2
